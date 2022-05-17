#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
public:
//log4(x) = log(x) / log(4) = 1/2 * log(x) / log(2) = 1/2 * log2(x)
//Syntax for returning natural logarithm:
//result = log(x)

//Syntax for returning logarithm (base-10 logarithm) of the argument.
//result = log10(x)
    bool isPowerOfFour(int n) {
        //bug: for float, cannot use %
        //in c++, can use fmod, this can truncate the number/denom
        //fmod returns a float number
        //e.g. 5.3 % 2 == 1.3
        return (n > 0) && fmod(log10(n) / log10(4), 1) == 0;
    }
};