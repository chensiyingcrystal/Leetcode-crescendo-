#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n)); //dp: unique paths from starting point to destination
        dp[0][0] = 1; // base case
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //must not modify dp[0][0]!!!
                if (i - 1 >= 0) { //evaluate out of boundary case
                    dp[i][j] = dp[i - 1][j];
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j - 1];
                } 
            }
        }
        return dp[m - 1][n - 1];
    }
};