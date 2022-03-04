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

    int singleNonDuplicate(vector<int>& nums) {
        //技巧：如果已经考虑到special case了，不管后面能不能照顾到，先写下来
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];
            //不要想当然觉得两边都是奇数或者偶数，遇到奇偶数的情况要分开考虑
            if (mid % 2 == 0 && nums[mid] == nums[mid - 1] || mid % 2 != 0 && nums[mid] == nums[mid + 1]) right = mid;
            else left = mid;
        }
        if (left - 1 >= 0) return nums[left] == nums[left - 1]? nums[right] : nums[left];
        else return nums[right] == nums[right + 1]? nums[left] : nums[right];
    }
};