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
//control word length each time,one character -> two -> three..., base case -> next state -> eventual state
//dp formula: dp[i][j] --- from index i to j if s[i] to s[j] is a palindrome
//            dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]) 
//base case: dp[i][i] = 1, dp[i][i + 1] = (s[i] == s[i + 1])
//time complexity: o(n2), space complexity: o(n2)
    string longestPalindrome(string s) {
        //result
        const int n = s.size();
        //initialize, if not, then we need to push back every time
        vector<vector<int> > dp(n, vector<int>(n));
        int maxLen = 1, start = 0;
        //base case
        for (int i = 0; i < n - 1; i++) {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            //update result for two character case
            if (dp[i][i + 1] && maxLen == 1) {
                maxLen = 2;
                start = i;
            }
        }
        dp[n - 1][n - 1] = 1;
        //begin dp(k to control the length for each time; i and j are two ends)
        for (int k = 2; k < n; k++) {
            int i = 0, j = k;
            while (i <= n - k - 1 && j < n) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                //update result for cases in which character's length is more than two
                if (dp[i][j] && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                    //break here is wrong!!!!
                    //we need to know every case before next cars in order to fectch the next value
                }
                i++, j++;
            }
        }
        //substr has o(n) time complexity
        return s.substr(start, maxLen);
    }

//Soluton2: dp, space complexity o(1), from one point or two and then expand
    string longestPalindrome(string s) {
        const int n = s.size();
        //result
        int maxLen = 0, start = 0;
        // begin for loop
        for (int i = 0; i < n; i++) {
            int curLen = max(getLen(s, i, i), getLen(s, i, i + 1));
            if (curLen > maxLen) {
                maxLen = curLen;
                //counting start should consider the even number and odd number of length case
                start = i - (curLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    //return the maximum length of a palindrome that is expanded from a point or two points
    int getLen(string& s, int left, int right) {
        const int n = s.size();
        while (s[left] == s[right] && left >= 0 && right < n) {
            left--;
            right++;
        }
        return right - left - 1;
    }

};