#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }
//Solution1: dp, result recorded in a two-dimensional list, one character -> two -> three...
//dp formula: dp[i][j] --- from index i to j if s[i] to s[j] is a palindrome
//            dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]) 
//base case: dp[i][i] = 1, dp[i][i + 1] = (s[i] == s[i + 1])
//time complexity: o(n2), space complexity: o(n2)
    string longestPalindrome(string s) {
        //result
        vector<vector<int> > dp;
        int maxLen = 0, start = 0;
        //base case
        const int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        dp[n - 1][n - 1] = 1;
        //begin dp(k to control the length for each time; i and j are two ends)
        for (int k = 0; k < n; k++) {
            int i = 0, j = k;
            while (i <= n - 1 - k && j < n) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
            i++, j++;
        }





        
    }

};