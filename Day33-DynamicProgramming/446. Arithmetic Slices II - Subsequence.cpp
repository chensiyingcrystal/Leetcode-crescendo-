#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 2) return 0;
        vector<unordered_map<long long, int> > dp(n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long) (nums[i] - nums[j]);
                int sums = 0;
                if (dp[j].find(d) != dp[j].end()) {
                    sums = dp[j][d];
                }
                dp[i][d] += sums + 1;
                ans += sums; 
            }
        }
        return ans;
    }

};