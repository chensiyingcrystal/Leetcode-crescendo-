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
//第一种写法： 需要做后处理
    int searchInsert(vector<int>& nums, int target) {
        const int n = nums.size();
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        //后处理用straightforward的方式写，会更不容易出错
        if (nums[left] == target) return left;
        if (target < nums[left]) return 0;
        if (target > nums[right]) return n;
        return left + 1;
    }
//Second way to solve this question: 
//need to analysis choose which index when the loop terminated
    int searchInsert(vector<int>& nums, int target) {
        const int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        //The loop terminated when left > right(right = the last mid) or right < left(left = the last mid)
        //For the first situation, target is large than the element to the last mid, so it should be at the index of mid + 1, which is left or right+1
        //For the second situation, target is less than the element to the last mid, so it should be at the index of mid, which is also left or right+1
        return left;
    }

};