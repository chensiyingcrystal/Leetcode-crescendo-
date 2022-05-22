#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
//dfs: tle
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        return dfs(nums, 0, sum / 2);
    }

    bool dfs(vector<int>& nums, int i, int target) {
        //bug: wrong! since we don't have to choose nums[i], we cannot add the following line
        // if (nums[i] > target) return false;
        if (nums[i] == target) return true;
        if (i == nums.size() - 1) return false;

        return dfs(nums, i + 1, target - nums[i]) || dfs(nums, i + 1, target);
    }

//dp
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        
        //initialize: m+1 rows and n+1 columns
        //for 0 rows, dp[0][0]=true, dp[0][j](j>0)= false
        //for 0 columns, dp[i][0](i>=0)= true, no need to update
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            //when j < num, no need to update
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
    //小熊出的题，要同时返回得到的最大值
    bool canPartition(vector<int>& nums, vector<int>& value) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        
        vector<bool> dp(target + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            int val = value[i - 1];
            //when j < num, no need to update
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};