#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        vector<int> checked(n, 0);
        int count = 0;
        unordered_map<int, int> nums_index;
        for(int i = 0; i < n; i++) {
            nums_index[nums[i]] = i;
        }
        queue<int> q;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (!checked[i]) {
                q.push(i);
                count = 1;
                while(!q.empty()) {
                    int index = q.front();
                    q.pop();
                    if (nums_index.find(nums[index] + 1) != nums_index.end() && 
                        !checked[nums_index[nums[index] + 1]]) {
                        q.push(nums_index[nums[index] + 1]);
                        checked[nums_index[nums[index] + 1]] = 1;
                        count += 1;
                    }
                }
                ans = max(count, ans);
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}