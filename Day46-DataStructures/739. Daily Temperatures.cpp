#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:

    bool isValid(string s) {
        const int n = s.length();
        stack<char> s_stack;
        int i = 0;
        while (i < n) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                s_stack.push(c);
            }
            else {
                if (s_stack.empty()) return false;
                char top = s_stack.top();
                //in addition to checking stack is empty or not, we have to 
                //make sure that the brackets matches with each other
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
                s_stack.pop();
            }
            i++;
        }
        return s_stack.empty()? true : false;
    }
};