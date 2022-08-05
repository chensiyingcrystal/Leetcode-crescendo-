#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findDistinctSubarrays(vector<int> nums, int k) {
        int n = nums.size();
        set<vector<int> > ansSet;//use set instead of unordered_set to store vector
        for (int i = 0; i < n; i++) {
            int count = 0;
            vector<int> temp;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0) {
                    count++;
                    if (count > k) break;
                }
                temp.push_back(nums[j]);
                ansSet.insert(temp);
            }
        }
        return ansSet.size();
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> stock = {2, 2, 5, 6, 9, 2, 11, 9, 2, 11, 12};
    int pos = ss->findDistinctSubarrays(stock, 1);
    cout << pos << endl;
    return 0;
}