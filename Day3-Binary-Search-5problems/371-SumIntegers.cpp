#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (uint32_t) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};


int main() {
    Solution* ss = new Solution();
    int result = ss->getSum(-1, 1);
    cout << result;
}