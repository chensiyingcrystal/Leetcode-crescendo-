#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = INT_MAX - 1;
            for (int j = 1; j * j <= i; j++) {
                tmp = min(tmp, dp[i - j * j]);
            }
            dp[i] = tmp + 1;
        }
        return dp[n];
    }
};