#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    Solution() {

    }

    int getDecreasingRatings(vector<int> ratings) {
        if (ratings.size() == 0) return 0;
        int ans = 1, pre = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] - ratings[i - 1] == -1) {
                pre = pre + 1;
                ans += pre;
            }
            else {
                pre = 1;
                ans += pre;
            }
        }
        return ans;
    }






};

int main() {
    Solution* ss = new Solution();
    vector<int> num = {4, 3, 5, 4, 3};
    int ans = ss->getDecreasingRatings(num);
    cout << ans << endl;

    return 0;
}