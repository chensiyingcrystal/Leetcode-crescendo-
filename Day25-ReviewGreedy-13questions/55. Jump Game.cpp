#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //rule: loop through nums, record max jumping point
        //check if max jumping point is greater than the last index
        if (nums.size() == 1) return true;
        int max_jump = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max_jump = max(max_jump, nums[i] + i);
            if (max_jump >= nums.size() - 1) return true;
        }
        return false;
    }
};