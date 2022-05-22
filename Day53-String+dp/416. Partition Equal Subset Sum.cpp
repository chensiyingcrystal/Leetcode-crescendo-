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
    //小熊出的题，判断能否装满到j，如果能到话要同时返回得到的最大值，如果不能则为0
    //这里的考察点第一是要判断恰好能装满，这点很重要，不能直接取上两个状态的最大值
    //第二是学会用同一个数据记录两个结果，可以用pair，但是也可以用INT_MIN这样的无限值来表示不能装满
    int canPartition(vector<int>& nums, vector<int>& value) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return 0;
        int target = sum / 2;
        
        vector<int> dp(target + 1, INT_MIN);
        //初始值，只有以下情况是能够装满，则只有它具有初始值
        dp[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            int val = value[i - 1];
            for (int j = target; j >= num; j--) {
                //如果前两个状态都不能装满，则该状态也应该是不能装满
                if (dp[j] == INT_MIN && dp[j - num] == INT_MIN) {
                    dp[j] = INT_MIN;
                }
                //如果有任一状态能够装满，则直接返回两者最大值
                else {
                    dp[j] = max(dp[j], dp[j - num] + val);
                }
            }
        }
        //判断结果能装满则返回value，不能则返回0
        return dp[target] == INT_MIN? 0 : dp[target];
    }
};