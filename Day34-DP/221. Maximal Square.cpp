#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//对于此类问题，通用的解法就是固定尾部！！对于2D的来说，就是固定cell为右下角
//因此dp[i][j]为包含该cell为右下角方格的最大square的边长
//dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        int maxLen = 0;
        //固定一个，映射到另一个，不要混乱
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
                    maxLen = max(maxLen, dp[i + 1][j + 1]);
                }
            }
        }
        return maxLen * maxLen;
    }
};