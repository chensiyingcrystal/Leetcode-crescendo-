#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int getMaxBarrier(vector<int>& initialEnergy, int threshold) {
        int left = 0, right = *max_element(initialEnergy.begin(), initialEnergy.end());
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (helper(initialEnergy, mid, threshold)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }

        }
        return ans;


    }

    bool helper(vector<int>& initialEnergy, int val, long long threshold) {
        long long res = 0;
        for (int i = 0; i < initialEnergy.size(); i++) {
            res += (long long) max(initialEnergy[i] - val, 0);
        }
        return res >= threshold;
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> i = {4, 8, 7, 1, 2};
    int ans = ss->getMaxBarrier(i, 9);

    cout << ans << endl;
    return 0;


}