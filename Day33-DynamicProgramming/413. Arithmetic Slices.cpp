#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//这道题的子问题和母问题衔接的不是特别明显，需要一定的数学推导
//对于n个数字的等差数列，第i个数字拥有的组合方式总和为C(i-3+1,1) + C(i-4+1, 1) + ... + C(i-i+1, 1)
//这样子的话，可以观察得出dp[i] = d][i-1] + 1, 最后要求的答案其实是dp[0]+dp[1]+dp[2]+...+dp[n-1]
//要注意的是！！对于此种if的动规情形，一定要考虑if不成立的时候，子问题如何累积到母问题的
//这时候应该是当前数字不会产生新的组合方式，因此为0，对累积总数附加为0。
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        //每次想明白：curr是什么含义，sum又是什么含义
        int pre = 0, curr = 0, sums = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr = pre + 1;
            }
            //bug: forget to add this condition
            //if the arithmetic array breaks at some point, curr point set to 0清零，一切重计
            else {
                curr = 0;
            }
            sums += curr;
            pre = curr;
        }
        return sums;
    }

};