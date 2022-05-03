#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;



class Solution {
public:
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
            if (dfs(nums, sum, target, i + 1)) return true;
            sum -= nums[i];
        }
        return false;
    }

};
