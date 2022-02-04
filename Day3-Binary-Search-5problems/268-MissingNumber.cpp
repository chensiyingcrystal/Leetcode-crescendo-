#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

// xor method
// 0 ^ 0 = 0; 
// b ^ b = 0;
// 0 ^ a = a;
// a ^ b ^ b = a;

    int missingNumber(vector<int>& nums) {
        int m = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            m = m ^ i ^ nums[i - 1];
        }
        return m;
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