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
//压缩空间的办法，每一行遍历，新的值会覆盖原来的值，用变量存储cell左上角的值
//cell上方的值为其未覆盖前的当前值，其左边格子为其上一个值，可压缩空间至o(n)
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1);
        int maxLen = 0;
        //固定一个，映射到另一个，不要混乱
        int prev = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n + 1; j++) {
                //bug：这里要注意，由于是每行进行覆盖，对每个格子都要进行更新prev的操作
                //另外如果该格子在原来matrix的值不是1，也要对dp[j]进行更新，否则dp[j]永远表示的是其上方格子的值
                int temp = dp[j];
                if (matrix[i][j - 1] == '1') {
                    dp[j] = min(min(dp[j], dp[j - 1]), prev) + 1;
                    maxLen = max(maxLen, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxLen * maxLen;
    }
};