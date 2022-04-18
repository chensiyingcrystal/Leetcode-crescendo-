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
   vector<int> searchRange(vector<int>& nums, int target) {
       if (nums.empty()) return {-1, -1};
       const int n = nums.length();
       int left = 0, right = n - 1;
   }
};