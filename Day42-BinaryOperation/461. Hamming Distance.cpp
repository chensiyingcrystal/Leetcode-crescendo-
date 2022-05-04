#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//Time Complexity: \mathcal{O}(1)O(1), since the Integer is of fixed size in Python and Java, the algorithm takes a constant time.
// For an Integer of 32 bit, the algorithm would take at most 32 iterations.
    int hammingDistance(int x, int y) {
        //using XOR
        int z = x ^ y;
        //finding how many 1s in this resulting number
        int count = 0;
        while (z) {
            //get the last number and increment count depending on it
            //we can also use z % 2 == 1 to check if the last digit is 1
            //if z % 2 == 1, then the last digit is 1
            count += z & 1;
            //shifting z by 1
            z >>= 1;
        }
        return count;
    }

};