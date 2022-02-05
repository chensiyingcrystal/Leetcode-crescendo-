#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
    int climbStairs(int n) {
        if (n == 1) return 1;
        int i = 1;
        int result;
        int left = 1, right = 1;
        while (i < n) {
            result = left + right;
            left = right;
            right = result;
            i += 1;
        }
        return result;
    }
};


int main() {
    Solution* ss = new Solution();
    int result = ss->climbStairs(2);
    cout << result;
}