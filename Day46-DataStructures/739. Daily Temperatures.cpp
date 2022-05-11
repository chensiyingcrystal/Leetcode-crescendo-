#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
//自己写的第一种方法：超时
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //store result
        const int n = temperatures.size();
        vector<int> ans(n);
        //initialize a stack
        stack<int> stk;
        //loop through in reverse order each element in the temperatures array
        for (int i = n - 1; i >= 0; i--) {
            //special processing for the last element
            if (i == n - 1) {
                ans[i] = 0;
                stk.push(temperatures[i]);
                continue;
            }
            //for other elements, we have to count how many elements behind that
            //are smaller than it?
            int count = 0;
            stack<int> stk_tmp;
            while (!stk.empty() && stk.top() <= temperatures[i]) {
                stk_tmp.push(stk.top());
                stk.pop();
                count++;
            }
            //determine if the stk is already empty, if so, then ans[i] should equal to 0
            //otherwise, ans[i] = count + 1;
            ans[i] = stk.empty()? 0 : count + 1;
            //before pushing the element into the stack, we need to restore the stack back to the status before popping out elements
            while(!stk_tmp.empty()) {
                stk.push(stk_tmp.top());
                stk_tmp.pop();
            }
            //still need to push the element into the stack
            stk.push(temperatures[i]);
        }
    return ans;
    }
//第二种方法：使用map存储temperature和对应answer的键值对
//space: o(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //store result
        const int n = temperatures.size();
        vector<int> ans(n);
        unordered_map<int, int> record;
        //initialize a stack
        stack<int> stk;
        //loop through in reverse order each element in the temperatures array
        for (int i = n - 1; i >= 0; i--) {
            //special processing for the last element
            if (i == n - 1) {
                ans[i] = 0;
                record[temperatures[i]] = 0;
                stk.push(temperatures[i]);
                continue;
            }
            //for other elements, we have to count how many elements behind that
            //are smaller than it?
            int count = 0;
            while (!stk.empty() && stk.top() <= temperatures[i]) {
                count += record[stk.top()];
                stk.pop();
            }
            //determine if the stk is already empty, if so, then ans[i] should equal to 0
            //otherwise, ans[i] = count + 1;
            ans[i] = stk.empty()? 0 : count + 1;
            //still need to push the element into the stack
            record[temperatures[i]] = ans[i];
            stk.push(temperatures[i]);
        }
    return ans;
    }
//Method3: instead of initializing a stack of temperatures
//why not use a stack of indices?
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //store result
        const int n = temperatures.size();
        vector<int> ans(n);
        //initialize a stack
        stack<int> stk;
        //loop through in reverse order each element in the temperatures array
        for (int i = n - 1; i >= 0; i--) {
            //special processing for the last element
            if (i == n - 1) {
                ans[i] = 0;
                stk.push(i);
                continue;
            }
            //for other elements, we have to count how many elements behind that
            //are smaller than it?
            int count = 0;
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                count += ans[stk.top()];
                stk.pop();
            }
            //determine if the stk is already empty, if so, then ans[i] should equal to 0
            //otherwise, ans[i] = count + 1;
            ans[i] = stk.empty()? 0 : count + 1;
            //still need to push the element into the stack
            stk.push(i);
        }
    return ans;
    }
//Method4: more easy way to use monotonic stack template
//we don't need to count; instead what we need is the distance 
//between the index of the first greater number minus the current index
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //store result
        const int n = temperatures.size();
        vector<int> ans(n);
        //initialize a stack with indices of elements
        stack<int> stk;
        //loop through in reverse order each element in the temperatures array
        for (int i = n - 1; i >= 0; i--) {
            //do not need to specially process the last element
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            //determine if the stk is already empty, if so, then ans[i] should equal to 0
            //otherwise, ans[i] = stk.top() - i;
            ans[i] = stk.empty()? 0 : stk.top() - i;
            //still need to push the element into the stack
            stk.push(i);
        }
    return ans;
    }
};