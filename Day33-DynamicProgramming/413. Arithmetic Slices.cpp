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
//循序渐进找到简洁解法的步骤
//第一步：暴力解法：判断每个子数组是不是等差数列；time: o(n3)
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        int ans = 0;
        //长度至少为3的子数组的产生：i代表数组的头，j代表数组的尾
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                if (isArithmetic(nums, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    bool isArithmetic(vector<int>& nums, int start, int end) {
        for (int k = start + 2; k <= end; k++) {
            if (nums[k] - nums[k - 1] != nums[k - 1] - nums[k - 2]) {
                return false;
            }
        }
        return true;
    }
//仔细观察上面的代码，发现第二遍循环和helper function里面的执行过程有重复，为什么不可以合并呢？
//第二步解法：双指针; time: o(n2)
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        int ans = 0;
        //这里i仍然代表头，而j代表的是尾同时也是判断等差数列的进度条k
        //如果nums[i:j]是等差数列，则j可以继续向后移动，否则就不用考虑j后面的了
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 2; j < n; j++) {
                if (nums[j] - nums[j - 1] == nums[j - 1] - nums[j - 2]) {
                    ans++;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }

//第三步的观察需要的技巧：头部固定, 每次考虑以end为结尾的数列，思考前一个数字的end和curr数字的end有什么关系
//类似的思路，我们可以构造出「自顶向下」的递归解法：
//定义递归函数 slices(A, end)的含义是区间 A[0, end] 中，以 end 作为终点的，等差数列的个数。
// A[0, end]内的以 end 作为终点的等差数列的个数，相当于在 A[0, end - 1]的基础上，增加了 A[end] 。
// 有两种情况：
  // A[end] - A[end - 1] == A[end - 1] - A[end - 2]时，说明增加的A[end]能和前面构成等差数列，那么 slices(A, end) = slices(A, end - 1) + 1；
  // A[end] - A[end - 1] != A[end - 1] - A[end - 2]时， 说明增加的 A[end]不能和前面构成等差数列，所以slices(A, end) = 0；
// 最后，我们要求的是整个数组中的等差数列的数目，所以需要把 0 <= end <= len(A - 1)0<=end<=len(A−1) 的所有递归函数的结果累加起来。
