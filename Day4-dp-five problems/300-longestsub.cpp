#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }
        int result = 0;
        for (auto a : ans) {
            result = max(result, a);
        }
        return result;
    }

    //not that good as above
    // int lengthOfLIS(vector<int>& nums) {
    //     const int n = nums.size();
    //     vector<int> i_longest(n, 1);
    //     i_longest[0] = 1;
    //     for(int i = 1; i < n; ++i) {
    //         bool choose = false;
    //         for(int j = 0; j < i; ++j) {
    //             if (nums[j] < nums[i]) {
    //                 i_longest[i] = max(i_longest[i], i_longest[j]);
    //                 choose = true;
    //             }
    //         }
    //         if (choose) i_longest[i] += 1; 
    //     }
    //     int longest_length = 0;
    //     for(auto i : i_longest) {
    //         longest_length = max(longest_length, i);
    //     }
    //     return longest_length;
    // }

}

int main() {
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    Solution* ss = new Solution();
    int result = ss->lengthOfLIS(nums);
    cout << result;
}