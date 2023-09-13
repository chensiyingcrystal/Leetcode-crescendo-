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

    vector<int> countMinimumCharacters(string& s, vector<string>& arr) {
        int n = s.length();
        //preprocess the string, record into the hash map
        unordered_map<char, vector<int>> charMap; //key: character, value: {freq, index}
        for (int i = 0; i < n; i++) {
            charMap[s[i]].push_back(i + 1);
        }
        
        //loop through the arr, calculate each string's character frequency, and calculate the index
        vector<int> ans;
        for (string& a : arr) {
            vector<int> freq(10, 0);
            for (int i = 0; i < a.length(); i++) {
                freq[a[i] - '0']++;
            }

            int maxIndex = -1;
            bool found = true;
            for (int i = 0; i < 10; i++) {
                char c = '0' + i;
                int f = freq[i];
                if (f == 0) continue;
                if (!charMap.count(c) || charMap[c].size() < f) {
                    found = false;
                    break;
                } else {
                    int res = charMap[c][f - 1];
                    maxIndex = max(maxIndex, res);
                }
            }

            if (!found) ans.push_back(-1);
            else ans.push_back(maxIndex);
        }
        return ans;

    }




    

};

int main() {
    Solution* ss = new Solution();
    string u1 = "064819848398";
    vector<string> u2 = {"088", "364", "07"};
    vector<int> ans = ss->countMinimumCharacters(u1, u2);
    for (int& i : ans) {
        cout << i << endl;
    }
    return 0;


}