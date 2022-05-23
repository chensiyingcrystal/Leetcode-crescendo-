#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
//如果这道题全都是大于0的数组，k也大于0，那么可以用如下dp做
//但是dp复杂度高，没有利用好连续subarray的特性，另外
//如果k和nums[i]都是可正可负数，那么无法用传统的方式固定每个j
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
            //bug:sum每一轮都需要更新，加入以该元素为结尾的和为k的数目
            sum += dp[k];
        }
        return sum;
    }
//prefix sum: 利用连续的数组！！因此不需要dp o(n2)复杂度
    int subarraySum(vector<int>& nums, int k) {
        //map records the number of subarrays that sum to key from 0 to ith elements
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