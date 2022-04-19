#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
//dp的第二种写法：到i、j为止，因此不需要额外max_Len做记录，最后的结果即为dp[m][n]
//dp[i][j]represents to the index i for the text1 and j for the text2
//the length of the longest common subsequence
//The formula should be: 
//dp[i][j] = dp[i-1][j-1] + 1, if text1[i-1] == text2[j-1]
//else: dp[i][j] = max(dp[i-1][j], dp[i][j-1]) 
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.length();
        const int n = text2.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};