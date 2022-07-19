#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }

//给定一个整数数组，计算长度为k的连续子数组的最大总和
//brute force
    int findkMaxSum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, start = nums[0];
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;
        for (int i = 1; i + k - 1 < n; i++) {
            sum = sum - start + nums[i + k - 1];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
//sliding window
    int findkMaxSum(vector<int>& nums, int k) {

    }
    
};