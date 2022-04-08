#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//技巧：类似之前的一题，如果第一遍从左上到右下，不能最终确定
//那么就再从另两个方向扫一遍
//本题需要细致观察，左上角的数字仅由第二遍扫决定，而右下角的数字相反
//第一行除开左上角数字，皆由三个方向的决定，因此第一遍和第二遍都需要扫到
//第一列除开左上角，皆由三个方向，最末行和最末列同理，其余格子皆由四个方向决定
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
        if (mat.empty()) return {};
        const int m = mat.size();
        const int n = mat[0].size();
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                }
                else {
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j > 0) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] != 0) {
                    if (i < m - 1) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    if (j < n - 1) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }
        return dp;
    }
};