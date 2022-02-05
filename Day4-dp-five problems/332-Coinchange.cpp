#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
    
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<int> ans;
    //     ans.push_back(0);
    //     int a = 1;
    //     while (a <= amount) {
    //         int a_fewest = INT_MAX;
    //         for (int i = 0; i < coins.size(); ++i) {
    //             if (a - coins[i] >= 0) {
    //                 a_fewest = min(a_fewest, ans[a - coins[i]]);
    //             }
    //         }
    //         if (a_fewest != INT_MAX) {
    //             ans.push_back(a_fewest + 1);
    //         }
    //         else {
    //             ans.push_back(a_fewest);
    //         }
    //         a += 1;
    //     }
    //     return ans[amount] == INT_MAX ? -1 : ans[amount];
    // }

//optimized method
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount + 1, INT_MAX);
        ans[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int min_value = INT_MAX;
            for (auto coin : coins) {
                if (i - coin >= 0) {
                    min_value = min(min_value, ans[i - coin]);
                }
            }
            if (min_value != INT_MAX) {
                ans[i] = min_value + 1;
            } 
        }
        return ans[amount] == INT_MAX ? -1 : ans[amount];
    }

};


int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int amount = 11;
    Solution* ss = new Solution();
    int result = ss->coinChange(coins, amount);
    cout << result;
}