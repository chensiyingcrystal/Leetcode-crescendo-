#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        unordered_map<string, vector<string> > map; //key:sorted string, value: vector
        for (string& s : strs) {
            string p = s;
            sort(p.begin(), p.end());
            map[p].push_back(s);
        }
        
        for (auto& p : map) {
            ans.push_back(p.second);
        }
        return ans;
    }
//generate frequency pattern as key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        unordered_map<string, vector<string> > map; //key:sorted string, value: vector
        for (string& s : strs) {
            string k = findAnagramPattern(s);
            map[k].push_back(s);
        }
        
        for(auto& p : map) {
            ans.push_back(p.second);
        }
        return ans;
    }
    
    string findAnagramPattern(string& s) {
        vector<int> freq(26, 0);
        for(char& c : s) {
            freq[c - 'a']++;
        }
        
        string res = "";
        for (int i = 0; i < 26; i++) {
            res += '#' + to_string(freq[i]);
        }
        return res;
        
    }
};