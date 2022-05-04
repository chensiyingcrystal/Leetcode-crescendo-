#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;



class Solution {
public:
//第一种方法：用dfs穷举subset找target sum类似的办法
//method1: brute force: enumerating all possible subsets
//time complexity: o(2^n)
//Space Complexity: \mathcal{O}(N)O(N) This space will be used to store the recursion stack. 
//We can’t have more than nn recursive calls on the call stack at any time.
    bool canPartition(vector<int>& nums) {
        int sum_of_nums = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_nums % 2 != 0) return false;
        int target = sum_of_nums / 2;
        return dfs(nums, 0, target, 0);
    }

    bool dfs(vector<int>& nums, int sum, int target, int first) {
        if (sum == target) {
            return true;
        }
        
        if (sum > target) {
            return false;
        }

        for (int i = first; i < nums.size(); i++) {
            sum += nums[i];
            //if not adding this clause, then all the dfs would return false
            if (dfs(nums, sum, target, i + 1)) return true;
            sum -= nums[i];
        }
        return false;
    }
//method2: similar recursive method
//First convert this question to finding elements that sum to 0.5 * (Sum of nums)
//The recursive way to do so is to thinking about the nums[0:-1] has what relationship with the result of nums[0:-2]
//If we choose the last item or if we not choose it, we will have different results
//We can generate the formula as:
//isSum(subSetSum, i) = isSum(subSetSum, i-1) || isSum(subSetSum - nums[i], i-1)
//The base case: 
//subSetSum == 0: return true
//subSetSum > 0 && i == 0: return false
//subSetSum < 0: return false
//time: o(2^n)(binary tree), space(o(n))
    bool canPartition(vector<int>& nums) {
        int sum_of_nums = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_nums % 2 != 0) return false;
        int target = sum_of_nums / 2;
        const int n = nums.size();
        return dfs(nums, n - 1, target);
    }

    bool dfs(vector<int>& nums, int i, int target) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;

        return dfs(nums, i - 1, target) || dfs(nums, i - 1, target - nums[i]);
    }
//method3: Top-down recursion + memorization
//Since the same subproblem is computed again and again, 
//the problem has Overlapping Subproblem property and can be solved using Dynamic Programming.
//time: o(m*n)
// In the worst case where there is no overlapping calculation, 
// the maximum number of entries in the memo would be m⋅n. 
// For each entry, overall we could consider that it takes constant time, 
// i.e. each invocation of dfs() at most emits one entry in the memo.
// The overall computation is proportional to the number of entries in memo. 
// Hence, the overall time complexity is \mathcal{O}(m \cdot n)O(m⋅n).
//space: o(m*n)
// We are using a 2 dimensional array of size (m⋅n) 
// and O(n) space to store the recursive call stack. 
// This gives us the space complexity as O(n) + O(m⋅n) = O(m⋅n)
    bool canPartition(vector<int>& nums) {
        int sum_of_nums = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_nums % 2 != 0) return false;
        int target = sum_of_nums / 2;
        const int n = nums.size();
        //这里可以是n和target的大小，但是为了便于和模板一样，可以各+1保证不会overflow
        vector<vector<int> > result(n, vector<int>(target + 1, 0));
        return dfs(nums, n - 1, target, result);
    }

    bool dfs(vector<int>& nums, int i, int target, vector<vector<int> >& result) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        
        //bug:假如只initialize了target的空间大小，最大的index是到target-1,因此会overflow
        //两种方法：第一是每次索引target的时候需要用target-1访问target的实际结果
        //第二种就是直接initialize target+1的空间大小，这样target能直接按照target访问
        if (result[i][target] == 1) return true;
        if (result[i][target] == 2) return false;
        bool ans = dfs(nums, i - 1, target, result) || dfs(nums, i - 1, target - nums[i], result);
        if (ans) result[i][target] = 1;
        else result[i][target] = 2;
        return ans;
    }
//method4: bottom up dynamic programming
//dp[i][j]: nums containing the former ith elements, whether or not if some of elements could
//form its subset that can add up to j
//time: o(mn); space: o(mn)
    bool canPartition(vector<int>& nums) {
        int sum_of_nums = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_nums % 2 != 0) return false;
        int target = sum_of_nums / 2;
        const int n = nums.size();

        vector<vector<bool> > result(n + 1, vector<bool>(target + 1, false));
        for (int i = 0, j = 0; i < n + 1; i++) result[i][j] = true;
        for (int i = 0, j = 1; j < target + 1; j++) result[i][j] = false;
        for (int i = 1; i < n + 1; i++) {
            int num = nums[i - 1];
            for (int j = 1; j < target + 1; j++) {
                if (j >= num) {
                    result[i][j] = result[i - 1][j] || result[i - 1][j - num];
                }
                else {
                    result[i][j] = result[i - 1][j];
                }
            }
        }
        return result[n][target];
    }
//method5: bottom up dynamic programming + space compress
//time: o(mn); space: o(n)
    bool canPartition(vector<int>& nums) {
        int sum_of_nums = accumulate(nums.begin(), nums.end(), 0);
        if (sum_of_nums % 2 != 0) return false;
        int target = sum_of_nums / 2;
        const int n = nums.size();

        vector<bool> result(target + 1, false);
        //初始值即为i=0时候那一行的值
        result[0] = true;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = target; j >= num; j--) {
                result[j] = result[j] || result[j - num];
            }
        }
        return result[target];
    }
};
