#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.size();
        const int m = text2.size();
        vector<int> p(m + 1, 0);
        vector<vector<int> > longestsub(n + 1, p);
        for(int i = 1; i < n + 1; ++i) {
            for(int j = 1; j < m + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    longestsub[i][j] = longestsub[i - 1][j - 1] + 1;
                }
                else {
                    longestsub[i][j] = max(longestsub[i - 1][j], longestsub[i][j - 1]);
                }
            }
        }

        return longestsub[n][m];
    }

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution* ss = new Solution();
    int result = ss->longestCommonSubsequence(text1, text2);
    cout << result;
}