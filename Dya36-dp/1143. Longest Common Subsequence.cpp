#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
//dp[i][j]represents to the index i for the text1 and j for the text2
//the length of the longest common subsequence
//The formula should be: 
//dp[i][j] = dp[i-1][j-1] + 1, if text1[i] == text2[j]
//else: dp[i][j] = max(dp[i-1][j], dp[i][j-1]) 
    int longestCommonSubsequence(string text1, string text2) {

        





  }
};