#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int maxRight = INT_MIN;
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (prices[i + 1] > maxRight) {
                maxRight = prices[i + 1];
            }
            maxProfit = max(maxProfit, maxRight - prices[i]);
        }

        if (maxProfit < 0) {
            return 0;
        }
        return maxProfit;
    }
};

int main() {
    vector<int> price {7, 1, 5, 3, 6, 4};
    Solution* ss = new Solution();
    cout << ss->maxProfit(price) << endl;
}