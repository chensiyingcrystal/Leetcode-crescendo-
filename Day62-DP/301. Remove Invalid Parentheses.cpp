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
// Time Complexity : O(2^N)
// since in the worst case we will have only left parentheses in the expression and 
//for every bracket we will have two options 
// Space Complexity : O(N)
//because we are resorting to a recursive solution and for a recursive solution 
//there is always stack space used as internal function states are saved onto a stack 
//during recursion. The maximum depth of recursion decides the stack space used. 
//Since we process one character at a time and the base case for the recursion is 
//when we have processed all of the characters of the expression string, 
//the size of the stack would be O(N). Note that we are not considering the space required to store the valid expressions. We only count the intermediate space here.
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
//Solution3: 进一步时间的优化（backtrack剪枝）
//剪枝的思路来源于：我们其实可以获得应该丢弃的左括号和右括号的数量
//这样可以对于丢弃的情况进行剪枝
//注意这种情况下我们仍然要对于右括号加入的情况进行限制，否则仍然会出错，试想第一个就是右括号的情况

//Time Complexity : The optimization that we have performed is simply a better form of pruning. 
//Pruning here is something that will vary from one test case to another. 
//In the worst case, we can have something like ((((((((( and the left_rem = len(S) 
//and in such a case we can discard all of the characters because all are misplaced. 
//So, in the worst case we still have 2 options per parenthesis and 
//that gives us a complexity of O(2^N)
//Space Complexity : The space complexity remains the same i.e. O(N)as previous solution. 
//We have to go to a maximum recursion depth of N before hitting the base case. 
//Note that we are not considering the space required to store the valid expressions. 
//We only count the intermediate space here.

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        string temp = "";
        pair<int, int> discarded = discardInvalidParentheses(s);
        int discarded_left = discarded.first;
        int discarded_right = discarded.second;
        backtrack(s, ans, temp, 0, 0, discarded_left, discarded_right, 0);
        return vector<string>(ans.begin(), ans.end());
    }
    
    void backtrack(string& s, unordered_set<string>& ans, string& temp, int leftcount, int rightcount, int discarded_left, int discarded_right, int first) {
        if (first == s.length()) {
            //对于最终情况，因为我们在下面限制了右括号一路上不能大于左括号，因此
            //这里我们只需要判断左右丢弃数量达到了，这种状态就已经是最少丢弃字符情况了
            if (discarded_left == 0 && discarded_right == 0) {
                ans.insert(temp);
            }
            return;
        }
        //字母的情况不受影响
        if (s[first] != '(' && s[first] != ')') {
            temp += s[first];
            backtrack(s, ans, temp, leftcount, rightcount, discarded_left, discarded_right, first + 1);
            temp.pop_back();
        }
        else {
            if (s[first] == '(') {
                //丢弃的情况可以剪枝
                if (discarded_left > 0) backtrack(s, ans, temp, leftcount, rightcount, discarded_left - 1, discarded_right, first + 1);
                //加入的情况不受影响
                temp += s[first];
                backtrack(s, ans, temp, leftcount + 1, rightcount, discarded_left, discarded_right, first + 1);
                temp.pop_back();
            }
            else if (s[first] == ')') {
                if (discarded_right > 0) backtrack(s, ans, temp, leftcount, rightcount, discarded_left, discarded_right - 1, first + 1);
                //右括号加入的情况仍然要受到限制
                if (rightcount < leftcount) {
                    temp += s[first];
                    backtrack(s, ans, temp, leftcount, rightcount + 1, discarded_left, discarded_right, first + 1);
                    temp.pop_back();
                }
            }
        }
        
        return;
        
    }
    
    pair<int, int> discardInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (auto& c : s) {
            if (c == '(') {
                left += 1;
            }
            else if (c == ')') {
                if (left != 0) left--;
                else {
                    right += 1;
                }
            }
        }
        return {left, right};
    }
};