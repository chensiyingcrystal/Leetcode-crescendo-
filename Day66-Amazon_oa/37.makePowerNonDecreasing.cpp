#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    Solution() {

    }
    
    int makePowerNonDecreasing(vector<int> power) {
        int n = power.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            power[i] += ans;
            if (power[i] < power[i - 1]) {
                ans += power[i - 1] - power[i];
                power[i] = power[i - 1];
            }
        }
        return ans;
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> power = {3, 4, 1, 6, 2};
    int middleMax = ss->makePowerNonDecreasing(power);
    cout << middleMax << endl;
    
    return 0;
}