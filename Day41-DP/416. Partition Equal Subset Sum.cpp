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
        if (target > 0 && i == 0) return false;
        if (target < 0) return false;

        return dfs(nums, i - 1, target) || dfs(nums, i - 1, target - nums[i]);
    }
};
