#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

//第一遍错误原因（方程定义错误）错误方程： f(n) = f(n - 2) + nums[n], f的定义为一定要包含自身，实际上这个决定应该是自动判决的
//自动判定是否包含自身的方程并不会导致重复，正确方程 f(n) = max(f(n - 2) + nums[n], f[n - 1])
//计算index太慢，正确应该是以rob的i为主，再换算成为nums的j
    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> rob(n + 2);
        rob[0] = 0;
        rob[1] = 0;
        for(int i = 2; i < n + 2; ++i) {
            rob[i] = max(rob[i - 2] + nums[i - 2], rob[i - 1]);
        }
        return rob[n + 1];   
    }


}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    Solution* ss = new Solution();
    int result = ss->rob(nums);
    cout << result << endl;
    return 0;
}