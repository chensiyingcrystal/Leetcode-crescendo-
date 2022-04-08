#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> sums;
        int tmp;
        backtrack(grid, 0, 0, tmp, sums);
        int ans = INT_MAX;
        for (int i = 0; i < sums.size(); i++) {
            ans = min(sums[i], ans);
        }
        return ans;
    }

    void backtrack(vector<vector<int> >& grid, int i, int j, int& tmp, vector<int>& sums) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            tmp += grid[i][j];
            sums.push_back(tmp);
            tmp -= grid[i][j];
            return;
        }

        tmp += grid[i][j];
        if (i + 1 < grid.size()) backtrack(grid, i + 1, j, tmp, sums);
        if (j + 1 < grid[0].size()) backtrack(grid, i, j + 1, tmp, sums);
        tmp -= grid[i][j];
    }
//自己写的dp
//直接在原矩阵上修改不会影响结果，因此可压缩空间至o(1)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
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