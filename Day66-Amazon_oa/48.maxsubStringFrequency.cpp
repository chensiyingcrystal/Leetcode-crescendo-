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


    int getMaxSubstringFrequency(string s) {
        //record each character's cumulative frequency
        vector<int> ans(26, 0);
        //record last round's max frequency and freq
        int maxFreq = INT_MIN;
        vector<int> freq(26, 0);
        //record last round characters with max frequency
        unordered_set<int> lastMaxFreq;

        //go through the string ans update characters with max freq and ans
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            freq[index]++;
            if (freq[index] > maxFreq) {
                lastMaxFreq.clear();
                lastMaxFreq.insert(index);
                maxFreq = freq[index];
            }
            else if (freq[index] == maxFreq) {
                lastMaxFreq.insert(index);
            }
            
            for (auto& k : lastMaxFreq) {
                ans[k]++;
            }
        }

        int res = INT_MIN;
        for (int& a : ans) {
            res = max(res, a);
        }
        return res;
    }
    

    

};

int main() {
    Solution* ss = new Solution();
    string s = "abbcca";
    int pos = ss->getMaxSubstringFrequency(s);
    cout << pos << endl;
    return 0;


}