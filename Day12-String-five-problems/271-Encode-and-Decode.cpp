#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }

    char c = '#';
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for (string s : strs) {
            ans += to_string(s.size()) + c + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        
        int i = 0;
        while (i < s.size()){
            //get the index of delimeter
            int delimeterIdx = s.find(c, i);
            //get the size number: from start, deli - i steps, not counting the end
            //stoi: string to int
            int stringSize = stoi(s.substr(i, delimeterIdx - i));  
            ans.push_back(s.substr(delimeterIdx + 1, stringSize));
            
            i = delimeterIdx + stringSize + 1;            
        }
        return ans;
    }

};