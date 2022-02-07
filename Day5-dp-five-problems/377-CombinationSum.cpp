#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {

    }

//初始的错误解法： 原因（不知道初始值怎么定义）
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> ways(target + 2);
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                ways[i] += ways[i - j];
            }
        }
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