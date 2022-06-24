#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    Solution() {


    }
//The first time solution: naive backtrack(tle)
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string temp = "";
        backtrack(s, temp, ans, 0);
        
        unordered_map<int, vector<string>> map;
        int min_diff = INT_MAX;
        for (auto& new_s : ans) {
            int diff = s.size() - new_s.size();
            map[diff].push_back(new_s);
            min_diff = min(min_diff, diff);
        }
        return map[min_diff];
    }
    
    void backtrack(string& s, string& temp, unordered_set<string>& ans, int first) {
        if (first == s.size()) {
            if(isValidString(temp)) {
                ans.insert(temp);
            }
            return;
        }
        
        temp += s[first];
        backtrack(s, temp, ans, first + 1);
        if (s[first] == '(' || s[first] == ')') {
            temp.pop_back();
            backtrack(s, temp, ans, first + 1);
        }
        else {
            temp.pop_back();
        }
        
    }
    
    bool isValidString(string temp) {
        if (temp == "") return true;
        stack<char>stk;
        for (char& c : temp) {
            if (c == '(') {
                stk.push(c);
            }
            else if (c == ')') {
                if (stk.empty()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};