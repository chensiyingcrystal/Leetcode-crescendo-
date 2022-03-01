#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int min_sum = 0;
        int largest_sum = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            largest_sum = max(largest_sum, sum - min_sum);

            if(sum < min_sum) {
                min_sum = sum;
            }

            
        }
        return largest_sum;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(5);  
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(8);
    Solution* ss = new Solution();
    int result = ss->maxSubArray(nums);
    cout << result;
}