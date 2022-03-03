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
//以下是解答之前33题的方法，稍微改动能在这题运用
// Formula: If a sorted array is shifted, if you take the middle, always one side will be sorted. Take the recursion according to that rule.
// 1- take the middle and compare with target, if matches return.
// 2- if middle is bigger than or equal with left side, it means left is sorted
// 2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
// 2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
// 3- if middle is less than left side, it means right is sorted
// 3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
// 3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)
//当元素设计为允许重复时，还能否用上述算法呢？哪里发生了变化呢？
//改变的地方：不能仅仅依靠中间元素比左边小还是大来判定左右是否sort
//原来元素不可以重复时，断层右边的肯定比左边初始值要小，因为那个位置就是发生切割的地方，而原来顺序肯定是递增的
//现在断层两边的特性都是可以比大于等于左边的，因此要对等于left的情况特殊考虑
//办法：收敛范围，让half发生偏移
//这种情况能满足题目要求： decrease step as much as possible
//time: best o(logN) when all elments are distince, worst: o(N) when all elements are the same
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[left]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else {
                left++;
            }
        }
        return false;
    }
};