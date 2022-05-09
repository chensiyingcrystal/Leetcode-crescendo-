#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

// keyword class + class name; end with semicolon
class MyQueue {
// access identifier
public:
    stack<int> stk1, stk2;
    //constructor
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if (!stk2.empty()) {
            int top = stk2.top();
            stk2.pop();
            return top;
        }
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int top = stk2.top();
        stk2.pop();
        return top;
    }

    int peek() {
        if (!stk2.empty()) {
            return stk2.top();
        }
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};
//可以将重复的步骤创建新的函数；variable命名注意
class MyQueue {
    stack<int> in, out;
public:
    MyQueue() {}
    void push(int x) {
       in.push(x);
    }

    int pop() {
       in2out();
       int x = out.top();
       out.pop();
       return x;
}

    int peek() {
       in2out();
       return out.top();
    }

    void in2out() {
       if (out.empty()) {
           while (!in.empty()) {
              int x = in.top();
              in.pop();
              out.push(x);
        }   } 
    }
    bool empty() {
       return in.empty() && out.empty();
    }
};