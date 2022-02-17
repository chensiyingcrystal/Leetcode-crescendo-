#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    Solution() {


    }

    bool isValid(string s) {
        stack<char> str;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                str.push(c);
            }

            else{
                //important, easy to be bug, test order
                if (str.empty()) return false;
                char p = str.top();
                if ((c == ')' && p == '(') || (c == ']' && p == '[') || (c == '}' && p == '{')) str.pop();
                else return false;
            }
        }
        //important, test counting
        return str.empty();
    }

};