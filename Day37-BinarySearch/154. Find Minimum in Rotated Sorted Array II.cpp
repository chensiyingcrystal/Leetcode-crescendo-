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


};