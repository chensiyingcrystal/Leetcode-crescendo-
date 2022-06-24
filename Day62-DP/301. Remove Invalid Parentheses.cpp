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
//非常多的不必要的步骤，代码结构不清晰，时间复杂度高
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string temp = "";
        backtrack(s, temp, ans, 0);
        //after getting the answer we select the elements with lease removed characters
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
            //!!!!!!!!!IMPORTANT BUG!!!!!!!!!
            //Here we say if it's a character, then we always count it and not discard it
            //However, we still need to pop it back because when it go back to its parent level
            //it should disappear otherwise in the parent level the first element is not
            //a character expected but this lower case letter; and when it pop back, what gets
            //popped back is this lower case letter but not the parentheses as expected.
            temp.pop_back();
        }
        
    }
//here we use a stack solution to figure out a string is a valid parentheses
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