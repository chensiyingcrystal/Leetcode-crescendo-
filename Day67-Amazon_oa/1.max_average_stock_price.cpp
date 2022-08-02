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

    int findCumulativeMax(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) return 0;
        int n = nums.size();
        int left = 0, right = 0;
        int maxSum = INT_MIN, tempSum = 0;
        unordered_map<int, int> visited;

        while (right < n) {
            int curr = nums[right];
            tempSum += curr;
            visited[curr]++;

            while (visited[curr] > 1) {
                int prev = nums[left];
                tempSum -= prev;
                visited.erase(prev);
                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(maxSum, tempSum);
            }

            right++;
        }

        return maxSum == INT_MIN? -1 : maxSum;




    } 

};