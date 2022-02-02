#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicate;
        for (int i = 0; i < nums.size(); ++i) {
            if (duplicate.count(nums[i])) {
                return true;
            }
            duplicate[nums[i]] = 1;
        }
        return false;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(1);  
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    Solution* ss = new Solution();
    bool result = ss->containsDuplicate(nums);
    cout << result;
}