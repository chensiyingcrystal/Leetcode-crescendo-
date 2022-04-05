#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//有了状态记录后，比原来纯粹递归（时间复杂度：2^n）
//时间复杂度： o(n)
    int climbStairs(int n) {
        //bug: initialize space
        int dp[n + 1];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n]; 
    }
    //空间压缩：o(n) -> o(1)
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int pre1 = 1, pre2 = 1, curr;
        for (int i = 2; i <= n; i++) {
            curr = pre1 + pre2;
            pre1 = pre2;
            pre2 = curr; 
        }
        return curr; 
    }
};