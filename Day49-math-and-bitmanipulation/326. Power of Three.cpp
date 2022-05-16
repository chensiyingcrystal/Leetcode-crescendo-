#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        //bug: communicate with interview in this case
        if (n < 0) return false;
        if (n % 3 != 0) return false;
        else return isPowerOfThree(n / 3);
    }
};