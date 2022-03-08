#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int step = 1, max_cover = nums[0], next_max_cover = 0;
        int i = 1; 
        while (i < nums.size()) {
            if (i > max_cover) {
                max_cover = next_max_cover;
                step++;
            }
            next_max_cover = max(next_max_cover, i + nums[i]);
            i++;
        }
        return step;
    }
};