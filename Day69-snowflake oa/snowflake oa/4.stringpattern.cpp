#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }
//discussion: https://leetcode.com/discuss/interview-question/2825744
    int calculateWays(int wordLen, int maxVowels) {
        //dp[i][j]: 0-ith string containing j consecutive vowels ending with ith character(j >= 0 && j <= maxVowels)
        //if ith character is not vowel
        //dp[i][j] = 21 * (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + ... + dp[i-1][min(i-1, maxVowel)]) if j == 0
        //dp[i][j] = 0 if (j != 0)
        //if ith character is vowel
        //dp[i][j] = 5 * dp[i-1][j-1] (j >= 1)
        vector<vector<int> > dp(wordLen + 1, vector<int>(maxVowels + 1, 0));
        int prevSum = 1, mod = 1e9 + 7;
        dp[0][0] = 1;

        for (int i = 1; i < wordLen + 1; i++) {
            int currSum = 0;
            for (int j = 0; j <= min(i, maxVowels); j++) {
                if (j == 0) {
                    dp[i][j] = 21 * prevSum % mod;
                } else {
                    dp[i][j] = 5 * dp[i - 1][j - 1] % mod;
                }
                currSum += dp[i][j];
                currSum %= mod;
            }
            prevSum = currSum;
        }
        return prevSum;
        
        

    }










    

};

int main() {
    Solution* ss = new Solution();
    int wordLen = 4, maxVowels = 2;
    int ans = ss->calculateWays(wordLen, maxVowels);

    cout << ans << endl;
    return 0;


}