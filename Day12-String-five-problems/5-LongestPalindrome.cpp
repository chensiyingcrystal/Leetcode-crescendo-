#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }
//Solution1: dp, result recorded in a two-dimensional list
//dp formula: dp[i][j] --- from index i to j if s[i] to s[j] is a palindrome
//            dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]) 
//base case: dp[i][i] = 1, dp[i][i + 1] = (s[i] == s[i + 1])
//time complexity: o(n2), space complexity: o(n2)
    string longestPalindrome(string s) {


        
    }

};