#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {

    }

//初始的错误解法： 原因（不知道初始值怎么定义）
//解决方法： 不是每个初始值都要存储。只有特殊边界值才需要；对于其他一致的值，可以用if语句对其进行control
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> ways(target + 1);
        ways[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(auto num : nums) {
                if(i >= num) ways[i] += ways[i - num];
            }
        }
        return ways[target];
    }
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution* ss = new Solution();
    int result = ss->combinationSum4(nums, 4);
    cout << result << endl;
    return 0;
}