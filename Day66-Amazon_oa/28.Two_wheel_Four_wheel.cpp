#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    Solution() {

    }

    vector<int> findTwoFourWheelCombinations(vector<int> nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) ans.push_back(0);
            else {
                ans.push_back(nums[i] / 4 + 1);
            }
        }
        return ans;
    }

    //2 -> 1(2)
    //4 -> 2(4, 2+2)
    //6 -> 2(2+4, 2+2+2) 
    //8 -> 3(4+4，2+2+4， 2+2+2+2)
    //10 -> 3(2+4+4， 2+2+2+4， 2+2+2+2+2)
    //2x + 4y = N
    //2(x+2y) = N
int findCombinations1(vector<int> nums, int volume) {
    int k = nums.size();
    vector<vector<int> > dp(k + 1, vector<int>(volume + 1));
    //dp[i][j]: number of ways make j volumes from 0~ith items
    //dp[i][j] = dp[i][j - items[i]] + dp[i - 1][j]
    for (int j = 0; j < volume + 1; j++) {
        dp[0][j] = 0;
    }
    for (int i = 0; i < k + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < volume + 1; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j - nums[i - 1]] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[k][volume];

}

int findCombinations2(vector<int> nums, int volume) {
    int k = nums.size();
    vector<int> dp(volume + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < volume + 1; j++) {
            if (j >= nums[i]) {
                dp[j] = dp[j - nums[i]] + dp[j];
            }
        }
    }
    return dp[volume];

}


int findCombinations3(vector<int> nums, int volume) {
    int k = nums.size();
    //dp[i][j]: make i volumes with last item j
    //dp[i][j] = dp[i - nums[j]][j] + dp[i - nums[j]][j - 1] + ... + dp[i - nums[i]][0]
    vector<vector<int> > dp(volume + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < volume + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            if (i >= nums[j - 1]) {
                for (int x = 0; x <= j; x++) {
                    dp[i][j] += dp[i - nums[j - 1]][x]; 
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    for (int x = 0; x < k + 1; x++) {
        ans += dp[volume][x];
    }
    return ans;

} 

};

int main() {
    Solution* ss = new Solution();
    vector<int> nums = {2, 4};
    vector<int> test = {2, 4, 6, 8, 10};
    for (int num : test) {
        int ans = ss->findCombinations2(nums, num);
        cout << ans << endl;
    }



    return 0;
}





