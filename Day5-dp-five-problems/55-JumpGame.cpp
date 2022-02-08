#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
//初始解法： 时间复杂度o(n2), 降低复杂度：要利用最大的特点
    // bool canJump(vector<int>& nums) {
    //     const int n = nums.size();
    //     vector<bool> result(n, false);
    //     result[0] = true;
    //     for(int i = 1; i < n; ++i) {
    //         for(int j = i - 1; j >= 0; --j) {
    //             if((nums[j] >= (i - j)) && result[j]) {
    //                 result[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return result[n - 1];
    // }

//正向移动
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int max_length = 0;
        for(int i = 0; i < n; ++i) {
            if(i > max_length) return false;
            int i_length = i + nums[i];
            max_length = max(max_length, i_length);
        }
        return max_length >= (n - 1);
    }

//反向移动
    bool canJump(vector<int>& nums) {
        const int n = nums.size();
        int last_index = n - 1;
        for(int i = n - 1; i >= 0; --i) {
            if (i + nums[i] >= last_index) {
                last_index = i;
            }
        }
        return last_index == 0;
    }

};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    Solution* ss = new Solution();
    int result = ss->canJump(nums);
    cout << result << endl;
    return 0;
}