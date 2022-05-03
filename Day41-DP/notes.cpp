# include <vector>

using namespace std;
/**0-1背包问题
 * 输入：
 * w(volume): [1, 3, 5, 2, 9, 6]
 * v(value): [5, 8, 2, 7, 3, 1]
 * W(maximum volume): 10
*/
int getMaxValue(vector<int>& w, vector<int>& v, int W) {
    const int m = w.size(), n = W;
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++) {
        int wi = w[i - 1], vi = v[i - 1];
        for (int j = 1; j <= n; j++) {
            if (j >= wi) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wi] + vi);  
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

//compress space complexity to o(n)
int getMaxValue(vector<int>& w, vector<int>& v, int W) {
    const int m = w.size(), n = W;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < m + 1; i++) {
        int wi = w[i - 1], vi = v[i - 1];
        for (int j = n; j >= 1; j--) {
            if (j >= wi) {
                dp[j] = max(dp[j], dp[j - wi] + vi);  
            }
        }
    }
    return dp[n];
}