#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//理解题意！！！
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 31;
        while (n) {
            ans += ((n & 1) << i);
            //bug: n >> 1(not updating n)
            n >>= 1;
            i--;
        }
        return ans;
    }

};