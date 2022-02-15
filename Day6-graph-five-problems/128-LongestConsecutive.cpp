#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int longestConsecutive(vector<int>& nums) {
        // special case
        const int n = nums.size();
        // 标记
        unordered_set<int> checked;
        int count = 0;
        unordered_map<int, int> nums_index;
        for(int i = 0; i < n; i++) {
            nums_index[nums[i]] = i;
        }
        queue<int> q;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (!checked.count(nums[i])) {
                q.push(i);
                count = 1;
                checked.insert(nums[i]);
                while(!q.empty()) {
                    int index = q.front();
                    q.pop();
                    if (nums_index.find(nums[index] + 1) != nums_index.end() && !checked.count(nums[index] + 1)) {
                        q.push(nums_index[nums[index] + 1]);
                        checked.insert(nums[index] + 1);
                        count += 1;
                    }
                    if (nums_index.find(nums[index] -1) != nums_index.end() && !checked.count(nums[index]-1)) {
                        q.push(nums_index[nums[index] - 1]);
                        checked.insert(nums[index] - 1);
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