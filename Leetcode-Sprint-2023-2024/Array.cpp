#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0, right = 0;
        unordered_map<int, int> numMap;
        long long windowSum = 0, maxSum = INT_MIN;

        while (right < nums.size()) {
            int curr = nums[right];
            numMap[curr]++;
            windowSum += curr;
            
            //硬性控制条件
            while (right - left + 1 > k) {
                int past = nums[left];
                numMap[past]--;
                if (numMap[past] == 0) numMap.erase(past);
                windowSum -= past;
                left++;
            }

            if (right - left + 1 == k && numMap.size() == right - left + 1) {
                maxSum = max(maxSum, windowSum);
            }
            right++;
        }

        return maxSum == INT_MIN ? 0 : maxSum;
        
    }
};