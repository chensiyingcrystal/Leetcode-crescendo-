#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int> > valid(n, vector<int>(n));
        int count = 0;

        for (int len = 1; len <= n; len++) {
            for (int start = 0; len + start - 1 < n; start++) {
                int end = start + len - 1;
                if (len == 1) {
                    valid[start][end] = 1;
                }
                else if (len == 2) {
                    if (s[start] == s[end]) valid[start][end] = 1;
                    else valid[start][end] = 0;
                }
                else {
                    if (s[start] == s[end]) valid[start][end] = valid[start + 1][end - 1];
                    else valid[start][end] = 0;
                }
                count += valid[start][end];
            }
        }
        return count;
    }

};