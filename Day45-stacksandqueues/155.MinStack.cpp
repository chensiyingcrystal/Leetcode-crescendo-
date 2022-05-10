#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class MinStack {
public:
    int min_value = INT_MAX;
    stack<int> stk;

    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        min_value = min(min_value, val);
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};