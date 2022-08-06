#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findEarliestMonth(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        long long total = 0;
        for (int& num : nums) {
            total += num;
        }

        long long preSum = 0;
        double minAverage = INT_MAX;
        int ans;
        for (int i = 0; i <= n - 2; i++) {
            preSum += nums[i];
            //In order to use the double version, which returns a double, at least one of the ints must be explicitly casted to a double.
            double diff = preSum / (double)(i + 1) - (total - preSum) / (double)(n - i - 1); //use double 
            if (diff >= 0 && diff < minAverage) {
                minAverage = diff;
                ans = i;
            }
        }
        return ans + 1;

    }

    


};

int main() {
    Solution* ss = new Solution();
    vector<int> nums = {1,4,4,5,4,4,1};
    int pos = ss->findEarliestMonth(nums);
    cout << pos << endl;
    return 0;
}