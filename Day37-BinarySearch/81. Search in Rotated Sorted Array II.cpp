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
//but one thing we can know for sure is that the target is not on the left([left] = [mid], [mid] != target)
//so what we can instead do is increment left by 1, turning this problem in this case to o(n) time complexity.
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