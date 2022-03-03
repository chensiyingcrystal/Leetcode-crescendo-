#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
//更简便的同时寻找的算法: 类似递归，设计好base case，然后不断收敛边界，进行faith jump， if not return, return default value
// Formula: If a sorted array is shifted, if you take the middle, always one side will be sorted. Take the recursion according to that rule.
// 1- take the middle and compare with target, if matches return.
// 2- if middle is bigger than left side, it means left is sorted
// 2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
// 2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
// 3- if middle is less than right side, it means right is sorted
// 3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
// 3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)算法
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            //important bug: must add "=" here
            //test case: nums = [3, 1], target = 1
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
//拆分成多个子问题的解法：先找到pivot，再找target
    int findPivot(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int medium = (left + right) / 2;

        while(left < right and (right - left > 1)) {
            if(nums[left] < nums[medium] and nums[medium] > nums[right]) {
                left = medium;
            }
            else {
                right = medium;
            }
            medium = (left + right) / 2;
        }
        
        int pivot;
        if(nums[left] < nums[right]) {
            pivot = left;
        }
        else {
            pivot = right;
        }
        return pivot;
    }


    int binary_search(vector<int>& nums, int start, int end, int target) {
        int medium = (start + end) / 2;

        while(start < end and (end - start) > 1) {
            if (target < nums[medium]) {
                end = medium;
            }
            else {
                start = medium;
            }
            medium = (start + end) / 2;
        }

        if (target == nums[start]) {
            return start;
        }
        else if (target == nums[end]) {
            return end;
        }
        else {
            return -1;
        }
    }


    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 1) {
            if (nums[0] == target) {
                return 0;
            }
            else {
                return -1;
            }
        }

        int pivot = findPivot(nums);
        if (target <= nums[n - 1] and target >= nums[pivot]) {
            return binary_search(nums, pivot, n - 1, target);
        }
        else {
            return binary_search(nums, 0, pivot, target);
        }
    }
};


int main() {
    vector<int> nums;
    nums.push_back(4);  
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    Solution* ss = new Solution();
    int result = ss->search(nums, 0);
    cout << result;
}