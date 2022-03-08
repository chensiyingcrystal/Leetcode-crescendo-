#include <vector>

using namespace std;

class Solution {
public:
//贪心：能跳到本格！！！+不断更新跳到最远; 不是一昧地贪心
//如果能跳到最后则true
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_jump) return false;
            max_jump = max(max_jump, nums[i] + i);
        }
        return true;
    }
//另一种解法：不管跳几步，只看跳的最大覆盖范围，i只能在覆盖范围内跳跃，如果超过就是false
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i <= max_jump; i++) {
            max_jump = max(max_jump, nums[i] + i);
            if (max_jump >= nums.size() - 1) return true;
        }
        return false;
    }
//错误代码：
//错误原因：没有考虑到能否跳到本格的先决条件
    bool canJump(vector<int>& nums) {
        //rule: loop through nums, record max jumping point
        //check if max jumping point is greater than the last index
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        int max_jump = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max_jump = max(max_jump, nums[i] + i);
            if (max_jump >= nums.size() - 1) return true;
        }
        return false;
    }
};