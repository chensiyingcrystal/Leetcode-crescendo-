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
//First difficult part: understand the question
//Second clarify several edge cases:
   // "/"
   // "/a/"
   // "/../"
//data structure: stack
//how to process the string: first skip the "/", add the string into stack instead of characters, finally construct ans using valid strings in the stack
//reversely read the string from stk: use string concatenation
    string simplifyPath(string path) {
        //loop through our path and store the valid string in the stack
          //rule1: igonre the '/'
          //rule2: ignore the string "."
          //rule3: if we encounter "..": pop out the top string from the stack
        stack<string> stk;
        const int n = path.length();
        for(int i = 0; i < n; i++) {
            if (path[i] == '/') continue;
            //first split the path;
            //Split the input string using / as the delimiter
            //whatever we have between two / characters is either a directory name or a special character and we have to process them accordingly.
            string temp = "";
            //important!!!bug: i < n
            //anytime you reference i, must check its availability
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }
            //then process one component at a time
            if (temp == ".") continue;
            else if (temp == "..") {
                //the edge case : "/../"
                if (!stk.empty()) {
                    //anytime we want to pop something out from a stack, we need to check if it's already empty
                    stk.pop();
                }
            }
            else {
                stk.push(temp);
            }
        }
        
        //construct our answer using the valid strings in the stack
        string ans = "";
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        //need to check to avoid the original stack is empty
        return ans == ""? "/" : ans;

        
    }
};