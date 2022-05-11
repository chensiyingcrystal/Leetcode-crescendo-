#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class MinStack {
public:
//the prompt requires all the operations running in constant time, i.e.O(1) time
//need to cleverlly solve the problem: instead of creating one variable min_value for recording
//we need to record the min_value up to this current value so far
//in regard to storing two information, we could use array or pair type in the stack
    stack<pair<int, int> > min_stk;

    MinStack() {

    }
    
    void push(int val) {
        if (min_stk.empty()) {
            min_stk.push({val, val});
            return;
        }
        
        min_stk.push({val, min(val, min_stk.top().second)});
        return;
    }
    
    void pop() {
        min_stk.pop();
        
    }
    
    int top() {
        return min_stk.top().first;
        
    }
    
    int getMin() {
        return min_stk.top().second; 
    }
};