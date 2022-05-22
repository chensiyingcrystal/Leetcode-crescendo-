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
        //loop through the answer and add results together
        return sum;
    }
};