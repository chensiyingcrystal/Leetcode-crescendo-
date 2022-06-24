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
//We find this solution by thinking from dfs
//Below is the dfs implementation, which exceeds time limits
//Here we considered many replicate steps; Thus we can use dp to optimize it
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        
        int min_count = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            //unlike normal dfs or backtracking, the child cases have a total influence on parent case
            //we have to use recursive case thinking to figure out the relationship between parent case and child cases
            min_count = min(min_count, numSquares(n - i * i));
        }
        return min_count + 1;
        
    }
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        
        return dp[n];
        
    }
};