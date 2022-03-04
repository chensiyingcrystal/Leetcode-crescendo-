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
    //这种情况下用right - left > 1很简便：此时指针的移动也要发生改变，直接变为mid
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            //这样的写法容易造成integer overflow
            // int mid = (left + right) / 2;
            int mid = left + (right - left) / 2;
            //要应对没有rotate的情况
            if (nums[mid] > nums[left] && nums[mid] <= nums[right] || nums[mid] < nums[left]) right = mid;
            else if (nums[mid] > nums[left]) left = mid;
            else left++;
        }
        return min(nums[left], nums[right]);
    }
    
    //简化一下写法
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[left] && nums[mid] > nums[right]) left = mid;
            else if (nums[mid] == nums[left]) left++;
            else right = mid;
        }
        return min(nums[left], nums[right]);
    }
};