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

    vector<vector<int> > getApplicationPairs(int deviceCapacity, vector<vector<int> > foregroundAppList, vector<vector<int> > backgroundAppList) {
        vector<vector<int> > ans;
        int maxMemory = INT_MIN;
        sort(foregroundAppList.begin(), foregroundAppList.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        sort(foregroundAppList.begin(), foregroundAppList.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < foregroundAppList.size(); i++) {
            for (int j = 0; j < backgroundAppList.size(); j++) {
                int totalMemory = foregroundAppList[i][1] + backgroundAppList[j][1];
                if (totalMemory <= deviceCapacity && totalMemory >= maxMemory) {
                    if (totalMemory > maxMemory) ans.clear();
                    ans.push_back({foregroundAppList[i][0], backgroundAppList[j][0]});
                }
            }
        }
        return maxMemory == INT_MIN ? {{}} : ans;
    }




};

int main() {
    Solution* ss = new Solution();

    return 0;
}