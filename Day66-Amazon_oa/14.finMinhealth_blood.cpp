#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMinHealth(vector<int>& blood, int& armour) {
        //minHealth = sumOfBlood + 1 - min(armour, maxOfBlood);
        int sumOfBlood = 0, maxBlood = INT_MIN;
        for (int& b : blood) {
            sumOfBlood += b;
            maxBlood = max(maxBlood, b);
        }

        return sumOfBlood + 1 - min(armour, maxBlood);
    }

};