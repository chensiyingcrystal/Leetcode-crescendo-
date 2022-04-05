#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));          
    }

    int helper(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (end - start == 1) return max(nums[start], nums[end]);
        int pre1 = nums[start], pre2 = nums[start + 1], curr;
        for (int i = start + 2; i <= end; i++) {
            curr = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = curr;
        }
        return curr;
    }
};