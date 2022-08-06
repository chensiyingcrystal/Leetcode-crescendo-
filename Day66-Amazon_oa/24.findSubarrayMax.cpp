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

    int findSubarrayMax(vector<int> nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> visited;
        //priority_queue<int, vector<int>> pq; //cannot remove elemtns in c++ stl
        int maxNum = INT_MIN;

        while (right < n) {
            int curr = nums[right];
            visited[curr]++;
            pq.push(curr);

            while (visited[curr] > 1) {
                int leftNum = nums[left];
                visited[leftNum]--;
                left++;
            }

            if (right - left + 1 == k) {
                maxNum = max(maxNum, findMax());
            }
            right++;

        }
        return maxNum == INT_MIN? -1 : maxNum;
    }


};

int main() {
    Solution* ss = new Solution();
    string s = "abcabcd";
    vector<int> pos = ss->findCommonSuffix(s);
    for (auto& num : pos) {
        cout << num << endl;
    }
    return 0;
}