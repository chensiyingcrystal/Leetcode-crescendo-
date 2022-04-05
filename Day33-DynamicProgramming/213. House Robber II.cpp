#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//首尾相接的情况，这里既然我们知道首尾不能同时共存，我们可以分类考虑只有首或只有尾的情况，取最大值
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));          
    }

    int helper(vector<int>& nums, int start, int end) {
        //这里仍然要记得加限制条件
        if (start == end) return nums[start];
        if (end - start == 1) return max(nums[start], nums[end]);
        //bug：这里再次犯了同样的错误！！pre2的值是代表到第二所房子抢到最大值！！！
        int pre1 = nums[start], pre2 = max(nums[start], nums[start + 1]), curr;
        for (int i = start + 2; i <= end; i++) {
            curr = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = curr;
        }
        return curr;
    }
};