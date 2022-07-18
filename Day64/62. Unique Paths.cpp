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
//why we can use dynamic programming here?
    //initially, we can think of a recursion method or, backtracking 
    //however, if we use them, we will do a bunch of duplicate work
    //so we think about using memorization!! And that is how dp forms.
//MORE quick way to think of dp
   //observe data input size: m, n <= 100, we cannot use recursive ways 
//Some constraints if we can use dp
   //two directions, no opportunity to go back and forth, maintain in an order!
   //count unique paths instead of outputting all unique paths.

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