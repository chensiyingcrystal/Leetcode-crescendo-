#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//此题与上题一样，也是逐个考虑以end为结尾的等差子数组个数之和
//对于不连续的dp问题来说：要升维度（公差d），即再增加一轮循环，逐个考虑end的前一个元素
//此题的第二个trick：相比前一题，今天的题每次考虑的是两个数
//哈希表中记载的等差子数组的数量包含了两部分：第一部分就是通过延长上一个元素为结尾的等差数组所形成的新等差数组
//第二部分就是nums[i]与nums[j]形成的新的weak等差数组， 即[nums[i], nums[j]]
//dp[i][d]表示以nums[i]为结尾，[d]为公差的等差子数组个数
//算法思路为：dp[i][d] = dp[j][d] + 1(加的这个1为[nums[i], nums[j]]所新形成的weak数组)
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        vector<unordered_map<long long, int> > dp(n);
        int ans = 0;
        //以nums[i]为结尾
        for (int i = 1; i < n; i++) {
            //前一个元素和nums[j](由于不连续，前一个元素不再是旁边的，而是要逐个考虑)
            for (int j = 0; j < i; j++) {
                //题目中int的取值范围可能会造成int溢出，注意这里不能如下写，否则仍然会溢出
                // long long d = (long long) (nums[i] - nums[j]);
                long long d = (long long)nums[i] - (long long)nums[j];
                int sums = 0;
                //这里也可以不寻找，但map如果找不到key，会自动创建key，value设置为0
                //为了减少此步骤的操作时间，我们加入if control
                if (dp[j].find(d) != dp[j].end()) {
                    sums = dp[j][d];
                }
                //dp[i][d]表示以nums[i]为结尾，[d]为公差的等差子数组个数
                dp[i][d] += sums + 1;
                //ans只用加已形成的3个以上的等差数组，而不用增加weak数组
                ans += sums; 
            }
        }
        return ans;
    }

};