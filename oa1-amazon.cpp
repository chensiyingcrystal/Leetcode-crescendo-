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
        int ans = -1, sum = 0, count = 0, left = 0, right = 0;
        const int n = nums.size();

        while (right <= n - k) {
            sum += nums[right];
            count++;
            right++;
            map[right]++;

            while (map[right] > 1) {
                map[left]--;
                sum -= left;
                count--;
                left++;
            }

            if (count == k) {
                ans = max(ans, sum);
                sum -= left;
                count--;
                left++;
            }
        }

        return ans;


    }
};
