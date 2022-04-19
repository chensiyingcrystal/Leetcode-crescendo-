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
    //自己写的第一遍代码，注意考虑array有无rotate的情况（k=0）
    int search(vector<int>& nums, int target) {
        //special case where nums has only one number
        const int n = nums.size();
        //----------need to simplify-----------
        if (n == 1) {
            if (target == nums[0]) return 0;
            else return -1;
        }
        //first find the index of the pivot
        if (nums[0] > nums[n - 1]) {
            int pivot = findPivot(nums, n);
            //compare target with the value of the pivot to decide which side it is in
            //----------need to simplify-----------
            if (target >= nums[0] && target <= nums[pivot]) {
                return binarySearch(nums, target, 0, pivot);
            }
            else if (pivot + 1 <= n - 1 && target >= nums[pivot + 1] && target <= nums[n - 1]) {
                return binarySearch(nums, target, pivot + 1, n - 1);
            }
        }
        else {
            //----------put this line of code before-----------
            return binarySearch(nums, target, 0, n - 1);
        }
        return -1;
    }

    int findPivot(vector<int>& nums, int n) {
        //----------add: if not rotated, return 0-----------
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
                //pivot must on the right side of mid
                left = mid;
            }
            else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
//简化后的代码
        int search(vector<int>& nums, int target) {
        //special case where nums has only one number
        const int n = nums.size();
        if (n == 1) {
            return target == nums[0] ? 0 : -1;
        }
        //first find the index of the pivot
        if (nums[0] < nums[n - 1]) {
            return binarySearch(nums, target, 0, n - 1);  
        }
        int pivot = findPivot(nums, n);
            //compare target with the value of the pivot to decide which side it is in
        if (target >= nums[0]) {
            return binarySearch(nums, target, 0, pivot);
        }
        else if (pivot + 1 <= n - 1 && target < nums[0]) {
            return binarySearch(nums, target, pivot + 1, n - 1);
        }
        else {
            return -1;
        }
    }

    int findPivot(vector<int>& nums, int n) {
        //----------add: if not rotated, return 0-----------
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
                //pivot must on the right side of mid
                left = mid;
            }
            else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};