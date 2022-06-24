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
//Solution2: 优化点
//1-- 上述解法时间复杂度高的原因是每次到最后我们都要消耗o(n)的时间检查是不是valid string
//其实我们应用的是我们在某道题中学会的方法，但是！！那道题是同时有三种不同类型的括号需要同时判断
//而对于只有一种括号而言，我们只需要在途中保证右括号不会超过左括号并且在最后判断左右括号数量相等即可
//2-- 对于判断最小removed，我们需要用一个global variable记录最小remove，并且用另一个local变量记录removed
//当达到最小我们就清空并且更新vector，数量相等我们仅更新，而避免重复我们就用hash set就可以做到！
//记住这里必须要避重，且避重采用的方法是hash set
//3-- 分类讨论是字母 左括号 还是右括号的情况，这样结构会更清晰
    vector<string> removeInvalidParentheses(string s) {
        //get clear with what we need to keep track of(set as global variable) or what not
        int min_removed = INT_MAX;
        unordered_set<string> ans;
        string temp = "";
        backtrack(s, ans, temp, min_removed, 0, 0, 0, 0);
        return vector<string>(ans.begin(), ans.end());
    }
    
    void backtrack(string& s, unordered_set<string>& ans, string& temp, int& min_removed, int leftcount, int rightcount, int first, int removed) {
        if (first == s.length()) {
            if (leftcount == rightcount) {
                if (removed < min_removed) {
                    //learn this syntax
                    ans.clear();
                    ans.insert(temp);
                    min_removed = removed;
                }
                else if (removed == min_removed) {
                    ans.insert(temp);
                }
            }
            return;
        }
        
        if (s[first] != '(' && s[first] != ')') {
            temp += s[first];
            backtrack(s, ans, temp, min_removed, leftcount, rightcount, first + 1, removed);
            temp.pop_back();
        }
        else {
            if (s[first] == '(') {
                //不加的情况
                backtrack(s, ans, temp, min_removed, leftcount, rightcount, first + 1, removed + 1);
                //加的情况
                //注意下一层任何可能对母level产生影响的都需要pop back
                //技巧：这里我们将所有应该全局track的变量设置成为了global，不应对母level产生影响的设置成为了local
                //如果将leftcount rightcount这样的变量也用引用，那这些变量也需要在回到母level前++ --
                //代码会变得非常复杂，因此推荐这种模式写backtrack
                //分清楚哪些不该影响，哪些全局track，仅对于临时answer进行pop back，并且保证任何产生
                //影响的情况（如遇到letter）也要pop back
                temp += s[first];
                backtrack(s, ans, temp, min_removed, leftcount + 1, rightcount, first + 1, removed);
                temp.pop_back();
            }
            else if (s[first] == ')') {
                backtrack(s, ans, temp, min_removed, leftcount, rightcount, first + 1, removed + 1);
                //右边加入的情况进行限制
                if (rightcount < leftcount) {
                    temp += s[first];
                    backtrack(s, ans, temp, min_removed, leftcount, rightcount + 1, first + 1, removed);
                    temp.pop_back();
                }
            }
        }
        
        return;
        
    }
};