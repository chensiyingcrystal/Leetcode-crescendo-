#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//错误想法：max（奇数index加起来的和，偶数index加起来的和
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        //bug: pre2 is the max of two
        int pre1 = nums[0], pre2 = max(nums[0], nums[1]), curr;
        for (int i = 2; i < nums.size(); i++) {
            //bug：curr is already the sum_of_money
            curr = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = curr;
        }
        return curr;
    }
};