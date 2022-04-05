#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        int pre = 0, curr = 0, sums = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr = pre + 1;
                sums += curr;
                pre = curr;
            }
        }
        return sums;
    }

};