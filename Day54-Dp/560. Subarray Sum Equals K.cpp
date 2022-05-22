#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //dp[j]represents in this array(nums[0 : i]), the number of subarrays
        //that must end with nums[i] and that the sum of which equal to j
        //dp[j] = dp[j - nums[i]], if j > nums[i], else dp[j] = 0;
        //if j == nums[i], dp[j] = dp[j - nums[i]] + 1
        vector<int> dp(k + 1, 0);
        int sum = 0;
        for (int i = 1; i <= nums.size(); i++) {
            int num = nums[i - 1];
            for (int j = k; j >= 0; j--) {
                if (j < num) dp[j] = 0;
                if (j > num) dp[j] = dp[j - num];
                if (j == num) dp[j] = 1;
            }
            sum += dp[k];
        }
        return sum;
    }
//prefix sum: 利用连续的数组！！因此不需要dp o(n2)复杂度
    int subarraySum(vector<int>& nums, int k) {
        //map records the number of subarrays that sum to key
        unordered_map<int, int> map;
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int delta = sum - k;
            //if found delta, that means there exits a subarray before i that sum up to delta
            //then there must exits equal number of subarray that ends with nums[i] that add up to k
            if (map.count(delta)) {
                //increment the count, 每一次都加入以nums[i]为结尾的加起来等于k的subarray个数 
                count += map[delta];
            }
            map[sum] += 1;
        }
        return count;
    }
};