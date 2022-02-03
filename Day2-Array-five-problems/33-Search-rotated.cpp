#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

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