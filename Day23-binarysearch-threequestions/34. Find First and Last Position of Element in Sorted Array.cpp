#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        const int n = nums.size();
        int low = 0, high = n - 1;
        vector<int> ans;
        while (high - low > 1) {
            int half = (low + high) / 2;
            if (nums[half] == target) {
                ans.push_back(half);
                low = (low + half) / 2;
                high = (half + high) / 2;
            }
            else if (nums[half] > target) high = half;
            else low = half;
        }  

    }
};