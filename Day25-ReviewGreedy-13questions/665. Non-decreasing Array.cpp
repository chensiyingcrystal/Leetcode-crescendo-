#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        //special case
        if (nums.size() == 1) return true;
        //rule: if nums[i] >= nums[i - 1], nothing happened
        //but if not, we need to compare nums[i] with nums[i - 2];
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (i == 1 && nums[i] < nums[0]) {
                nums[0] = nums[i];
                count++;
                continue;
            }

            if (nums[i] < nums[i - 1]) {
                if (count == 1) return false;
                if (nums[i] < nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
                else {
                    nums[i - 1] = nums[i];
                }
                //bug: forgot to increment count
                count++;
            }
        }
        return true;
    }

};