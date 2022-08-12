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

    int getCeilExecution(vector<int> process) {
        int n = process.size();
        int i = 0, ans = 0;
        sort(process.begin(), process.end());

        while (i < n) {
            ans += process[i];

            int pre = process[i];
            while (i + 1 < n && process[i] == process[i + 1]) {
                i++;
                ans += (pre + 1) / 2;
                pre = (pre + 1) / 2;
            }

            i++;
        }
        return ans;
    }
    
    int getCeilExecution2(vector<int> process) {
        if (process.size() == 0) return 0;
        int n = process.size();
        sort(process.begin(), process.end());
        int i = 0, ans = process[0], pre = process[0];

        for (int i = 1; i < n; i++) {
            if (process[i] == process[i - 1]) {
                ans += (pre + 1) / 2;
                pre = (pre + 1) / 2;
            }
            else {
                ans += process[i];
                pre = process[i];
            }
        }
        return ans;
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> power = {5, 8, 4, 4, 8, 2};
    int mid = ss->getCeilExecution(power);
    cout << mid << endl;

    int mid2 = ss->getCeilExecution2(power);
    cout << mid2 << endl;
    return 0;
}