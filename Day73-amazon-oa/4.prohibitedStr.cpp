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

    int longestValidSubstring(string s, vector<string> prohibited) {
        unordered_set<string> wordSet(prohibited.begin(), prohibited.end());
        int left = 0, right = 0;
        int maxLen = INT_MIN;

        while (right < s.length()) {
            int curr = right;
            while (curr >= left && right - curr + 1 <= 10) {
                if (wordSet.count(s.substr(curr, right - curr + 1))) {
                    left = curr + 1;
                    break;
                }
                curr--;

            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen == INT_MIN ? 0 : maxLen;

        

       
        
    }



};

int main() {
    Solution* ss = new Solution();
    string s = "abcdapple";
    vector<string> arr = {"ab", "app", "le"};
    int ans = ss->riceBags(s, arr);
    cout << ans << endl;

    return 0;


}