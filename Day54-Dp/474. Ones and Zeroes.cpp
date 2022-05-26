#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //1. preprocessing the vector and get the number of 1s in each element and the total mount of characters in each string
        const int n = strs.size();
        vector<int> length(n);
        vector<int> ones(n);
        for (int i = 0; i < n; i++) {
            length[i] = strs[i].length();

            int one_count = 0;
            for (auto& c : strs[i]) {
                if (c == '1') one_count++;
            }
            ones[i] = one_count;
        }

        //2. build the dynamic programming model
        //objective: find the largest number of elements while meeting the following requirements:
        //first: the total characters in this string subset is 8
        //second: the largest number of 1s in this subset is 3
        //dp[i][j] represents the number of 1s and the largest number of elements in the subset that meets the above requirements
        //w[i] represents the number of characters of a string;
        //v[i] represents the number of '1' in the string

        vector<pair<int, int> > dp(9);
        dp[0] = make_pair(0, 0);
        for (int i = 1; i < n + 1; i++) {
            int w = length[i - 1];
            int v = ones[i - 1];
            for (int j = 8; j >= w; j--) {
                if (dp[j - w].first + v <= 3) {
                    if (dp[j - w].second > dp[j].second) {
                        dp[j] = dp[j - w];
                    }
                }
            }
        }
        return dp[8].second;
    }
};