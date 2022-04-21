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
//This question is different from 33 in that the input allows duplicate numbers
//which means that we need to seperate the situation where nums[mid] == nums[left]
//becuase in this case, we cannot tell if the chasm is on the left side of index mid or the right
//but one thing we can know for sure is that the target is not equal to the element to the left index([left] = [mid], [mid] != target)
//so what we can instead do is each time increment left index by 1, turning this problem in this case to o(n) time complexity.
//对于有重复元素的数组，不管之前的数组是有多少重复元素的部分，或者全部是重复元素
//只要不在元素相等的区域劈开，那么都可以按照33题的方式进行二分
//因为此时左右两部分肯定存在落差，我们可以肯定可以通过mid与left的关系判定chasm是在mid左侧还是右侧
//从而将target要么逼入单调区域要么丢弃单调区域最后逼向chasm区域
//但是如果在元素相等区域劈开，无法判定chasm出现在mid左边还是右边
//因此只能改用线性的方法将区间缩小
    bool search(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 1) return target == nums[0] ? true : false;

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                left++;
            }
        }
        return false;
    }
};