#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    uint32_t reverseBits(uint32_t n) {
        // uint32_t x = 1 >> 0;
        // cout << x;
        uint32_t reverse = 0;
        for(int i = 31; i >= 0; --i) {
            reverse += ((n >> i) & 1) << (31 - i);
        }
        return reverse;
    }

};


int main() {
    Solution* ss = new Solution();
    uint32_t result = ss->reverseBits(00000010100101000001111010011100);
    cout << result << endl;
}