#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    Solution() {

    }

    int findMinimumAddCharacters(string& searchWord, string& resultWord) {
        int m = searchWord.length(), n = resultWord.length();
        if (m == 0 && n == 0) return 0;
        if (n == 0) return -1;
        int ps = 0, pr = 0;
        while (ps < m && pr < n) {
            if (searchWord[ps] == resultWord[pr]) {
                ps++;
                pr++;
            }
            else {
                ps++;
            }
        }
        return n - pr;

    }

//if not must insert in the end
// s--> abc   r--> bca
// dp[i][j]: string end with s and string r end with jth, minimum insertion
// s--> a  r--> b   minInsertion = 1
// s--> ab r--> b   minInsertion = 0
// if (s[i] == r[j]) dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1] + 1)
// if (s[i] != r[j]) dp[i][j] = min(dp[i-1][j], dp[i][j-1] + 1)
//abcdx
//abc



    }
};