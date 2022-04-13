#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
//define a shorter string: text2 and a longer one, text1
//based on text2, dp[i]represents the longest common subsequence that ends with text2[i]
//The formula is: dp[i] = max(dp[i], dp[j] + 1), for j from 0 to i - 1, if text2[i] is in text1
//else: dp[i] = 0
//update the max_Len when looping through text2
    int longestCommonSubsequence(string text1, string text2) {
      //we wanna make sure that text2 is always the shorter one 
        if (text1.length() < text2.length()) {
            string tmp = text1;
            text1 = text2;
            text2 = tmp;
      }
        const int m = text1.length();
        const int n = text2.length();
        



  }
};