#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
//尾部的0由2x5而来，统计有几个（2，5）的完整配对，即min(2, 5)
//2总是比5多，统计有几个5即可
    int trailingZeroes(int n) {
        return n < 5? 0 : n / 5 + trailingZeroes(n / 5);
    }

};
