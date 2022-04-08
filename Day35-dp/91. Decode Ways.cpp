#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        const int n = s.length();
        vector<int> dp(n - 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0' || s.substr(i - 1, 2) > "27") {
                if (s[i] == '0') return 0;
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else {
                if (s[i] == 0) {
                    dp[i] = dp[i - 2];
                }
                else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        }
        return dp[n - 1];
    }
};