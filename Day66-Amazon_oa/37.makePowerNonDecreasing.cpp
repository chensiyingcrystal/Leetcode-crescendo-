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
        int n = power.size(), pre = 0, ans = 0;
        for (int i = 1; i < n; i++) {
            power[i] += pre;
            if (power[i] < power[i - 1]) {
                pre += power[i - 1] - power[i];
                ans += power[i - 1] - power[i];
            }
        }
        return ans;
    }


};

int main() {
    Solution* ss = new Solution();
    string s = "aabcdea";
    int middleMax = ss->findRedundancyGroup(s);
    cout << middleMax << endl;
    
    return 0;
}