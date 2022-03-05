#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        //record the last show-up of each character
        vector<int> last_show(26);
        for (int i = 0; i < s.length(); i++) {
            last_show[s[i] - 97] = i;
        }

        //loop through string s to determine all parts
        vector<int> ans;
        //bug: we should return the size of each part
        int start = 0;
        //这里减97和减‘a'结果都是一样的
        int update = last_show[s[0] - 97];
        for (int i = 0; i < s.length(); i++) {
            if (i <= update) {
                update = max(update, last_show[s[i] - 97]);
            }
            else {
                ans.push_back(update - start + 1);
                start = i;
                update = last_show[s[i] - 97];
            }
        }

        ans.push_back(update - start + 1);
        return ans;
    }
    

};