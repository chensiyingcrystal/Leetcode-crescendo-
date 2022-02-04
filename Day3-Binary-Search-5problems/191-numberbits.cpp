#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            int module = n & 1;
            if (module) {
                count += 1;
            }
            n = n >> 1;
        }
        return count;
    }
};


int main() {
    Solution* ss = new Solution();
    int result = ss->hammingWeight(00000000000000000000000000001011);
    cout << result;
}