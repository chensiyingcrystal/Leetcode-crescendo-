#include <vector>

using namespace std;

class Solution {
public:
//这道题的贪心思路很难想到，最主要是不要拘泥于跳几步，而是专注于最大覆盖范围
//在当前覆盖范围内，都是同样的步数，同时不断更新下一个最大覆盖范围，一旦超过当前覆盖范围，步数+1
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int step = 1, max_cover = nums[0], next_max_cover = 0;
        int i = 1; 
        while (i < nums.size()) {
            //超过当前最大覆盖范围后，当前最大覆盖范围更新，同时步数加1
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