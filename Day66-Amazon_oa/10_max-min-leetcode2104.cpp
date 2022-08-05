#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {

public:
    Solution() {

    }
    

    long long shipmentImbalance(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int minVal = nums[i], maxVal = nums[i];
            for (int j = i + 1; j < i; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                ans += maxVal - minVal;
            }
        }
        return ans;
    }



};