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
//第一遍写的，分类情况特别多
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] < nums[n - 1]) return nums[0];

        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
                left = mid;
            }
            else if (nums[mid] < nums[left] && nums[mid] <= nums[right] || nums[mid] > nums[left] && nums[mid] <= nums[right]) { 
                right = mid;
            }
            else {
                left++;
            }
        }
        return min(nums[left], nums[right]);
    }
//与153连贯的最佳写法！！
//此题还是需要不断靠近chasm区域，discard有序区域
//这里与153的不同点就在于出现了重复元素
//即mid与left元素相等时，不能判断chasm在mid左侧还是右侧
//此时可考虑作线性处理：收拢一侧，一旦断层处不再相等了，必出现高低落差，这样与153题其实是一样的了
    //注意只要不在相等处断层，其余处有重复元素对二分是没有影响的
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            //在被旋转过的数组中，如果nums[mid] == nums[right]时，必然有nums[mid] == nums[left]
            //但是对于单调递增的数组而言，上面并不成立
            //要想对旋转和未旋转的数组都向最小值靠近，这里写right--是对的
            //如果要想写left++,必须在while循环外增加对于未经旋转的单调数组的处理
            if (nums[mid] == nums[right]) right--;
            //与153同，找最小值时，要依据mid与right的关系判断，才能同时适用于单调未旋转数组
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};