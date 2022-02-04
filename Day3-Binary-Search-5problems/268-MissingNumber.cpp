#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
   Solution() {

   }


    int missingNumber(vector<int>& nums) {
        unordered_set<int> nums_set;
        const int n = nums.size();

        for(int i = 0; i < n; ++i) {
            nums_set.insert(nums[i]);
        }

        for(int i = 0; i <= n; ++i) {
            if (!nums_set.count(i)) return i;
        }

        return 0;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(1);
    Solution* ss = new Solution();
    int result = ss->missingNumber(nums);
    cout << result << endl;

}