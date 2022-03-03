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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        return {findFirst(nums, target), findLast(nums, target)};
    }

    int findFirst(vector<int>& nums, int& target) {
        const int n = nums.size();
        int low = 0, high = n - 1, leftmost = -1;
        while (low <=high) {
            int half = (low + high) / 2;
            if (nums[half] > target) {
                high = half - 1;
            }
            else if (nums[half] < target) {
                low = half + 1;
            }
            else {
                leftmost = half;
                high = half - 1;
            }
        }
        return leftmost;
    }

    int findLast(vector<int>& nums, int& target) {
        const int n = nums.size();
        int low = 0, high = n - 1, rightmost = -1;
        while (low <= high) {
            int half = (low + high) / 2;
            if (nums[half] > target) {
                high = half - 1;
            }
            else if (nums[half] < target) {
                low = half + 1;
            }
            else {
                rightmost = half;
                low = half + 1;
            }
        }
        return rightmost;
    }
};