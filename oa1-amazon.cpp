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

    int findMaxObservableSum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int ans = -1, sum = 0, left = 0, right = 0;
        const int n = nums.size();

        while (right <= n - k) {
            sum += nums[right];
            map[nums[right]]++;

            while (map[nums[right]] > 1) {
                map[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                ans = max(ans, sum);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return ans;


    }
};
