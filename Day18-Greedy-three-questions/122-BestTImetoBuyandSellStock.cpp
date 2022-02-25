#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//这里能运用贪心，是因为股票可以当天买卖，每天最大化利益，局部最优 -> 全局最优
    int maxProfit(vector<int>& prices) {
        int ans = 0; 
        int prev = prices[0];
        //bug: int i
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prev) {
                ans += prices[i] - prev;
            }
            prev = prices[i];
        }
        return ans;
    }

//优化代码，每天只收取正利益，累积起来就是最大利益
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }

};