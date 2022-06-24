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
//Here we can also use left < right
//But since we are used to practicing two modes
//Find a way to apply the modes to the problem
//随机应变
//这里应该考虑不同种类的情况对于同一种方法都适用；同时不要遗漏mid（因此这里不能用left <= right)
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return nums[left] > nums[right]? left : right;
    }
};