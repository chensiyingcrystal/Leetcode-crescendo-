#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size() - 1;
        int medium = (left + right) / 2;

        while(left < right and (right - left > 1)) {
            if(nums[left] < nums[medium]) {
                left = medium;
            }
            else {
                right = medium;
            }

            medium = (left + right) / 2;

        }
        return nums[right];
    }
};


int main() {
    vector<int> nums;
    nums.push_back(3);  
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(2);
    Solution* ss = new Solution();
    int result = ss->findMin(nums);
    cout << result;
}