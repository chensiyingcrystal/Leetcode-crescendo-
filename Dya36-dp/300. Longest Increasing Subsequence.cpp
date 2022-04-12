#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
//define dp[i] as the length of the longest increasing subsequence that 
//end with nums[i]
//loop through 0 to i-1, to find the number before nums[i]
//if nums[j] < nums[i], dp[i] = dp[j] + 1, update dp[i] during the loop
//use a variable named max_Len to record the maximum length of the longest subsequence
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 1;
        //initialize a vector array to record dp[i]
        vector<int> dp(n, 1);
        //create a variable named max_Len to record our final result
        int max_Len = 1;
        //loop through each nums[i] for i from 1 to n-1
        for (int i = 1; i < n; i++) {
            //loop through j from 0 to i-1 to find the number before nums[i]
            for (int j = 0; j <= i - 1; j++) {
                //use our formula and update dp[i] with maximum value under specific condition
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            //after the loop, we wanna update the max_Len for the whole sequence
            max_Len = max(max_Len, dp[i]);
        }
        return max_Len;
    }
};