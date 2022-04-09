#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        const int n = s.length();
        //这里要对dp扩容，添加虚拟的dp[0]
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            if (s[i - 2] == '0' || s.substr(i - 2, 2) >= "27") {
                if (s[i - 1] == '0') return 0;
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else {
                if (s[i - 1] == '0') {
                    dp[i] = dp[i - 2];
                }
                else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};