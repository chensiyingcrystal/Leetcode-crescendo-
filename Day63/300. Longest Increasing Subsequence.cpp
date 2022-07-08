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
//why is this a dynamic programming
    //First, the question is asking for the maximum or minimum of something. 
    //Second, we have to make decisions that may depend on previously made decisions, which is very typical of a problem involving subsequences.
//how to build dp status and equation?
    //1.state: dp[i] represents the length of the longest increasing subsequence that ends with the i^{th}i th element. 
    //1、明确 dp 数组所存数据的含义。这一步对于任何动态规划问题都很重要，如果不得当或者不够清晰，会阻碍之后的步骤。
    //2. transition between state: recurrence relation: dp[i] = max(dp[i], dp[j] + 1) for all j where nums[j] < nums[i] and j < i.
    //2、根据 dp 数组的定义，运用数学归纳法的思想，假设 dp[0...i-1] 都已知，想办法求出 dp[i]，一旦这一步完成，整个题目基本就解决了。
//!!但如果无法完成这一步，很可能就是 dp 数组的定义不够恰当，需要重新定义 dp 数组的含义；或者可能是 dp 数组存储的信息还不够，不足以推出下一步的答案，需要把 dp 数组扩大成二维数组甚至三维数组。
    //3、base case:  For this problem, we can initialize every element of dp to 1, since every element on its own is technically an increasing subsequence.
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 1, n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;

    }
};