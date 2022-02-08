#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int rob(vector<int>& nums) {
        //注意初始值界定的时候要提前判定没有该初始值的情况
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        const int n = nums.size();
        vector<int> start_rob(n, 0);
        vector<int> end_rob(n, 0);
        start_rob[0] = 0;
        start_rob[1] = nums[0];
        end_rob[0] = 0;
        end_rob[1] = nums[1];
        for(int i = 2; i < n; ++i) {
            start_rob[i] = max(start_rob[i - 2] + nums[i - 1], start_rob[i - 1]);
        }
        for(int j = 2; j < n; ++j) {
            end_rob[j] = max(end_rob[j - 2] + nums[j], end_rob[j - 1]);
        }
        return max(start_rob[n - 1], end_rob[n - 1]);     
    }

    //对空间进行压缩
    int rob(vector<int>& nums) {
        //注意初始值界定的时候要提前判定没有该初始值的情况
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        const int n = nums.size();
        int start1 = 0, start2 = nums[0], start_result;
        int end1 = 0, end2 = nums[1], end_result;
        for(int i = 1; i < n; ++i) {
            start_result = max(start1 + nums[i - 1], start2);
            start1 = start2;
            start2 = start_result;
        }
        for(int j = 1; j < n; ++j) {
            end_result = max(end1 + nums[j], end2);
            end1 = end2;
            end2 = end_result;
        }
        return max(start_result, end_result);     
    }

}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    Solution* ss = new Solution();
    int result = ss->rob(nums);
    cout << result << endl;
    return 0;
}