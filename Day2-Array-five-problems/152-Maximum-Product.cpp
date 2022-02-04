#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int min_temp = nums[0], max_temp = nums[0];
        int max_product = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(max_temp, min_temp);
            max_temp = max(max_temp * nums[i], nums[i]);
            min_temp = min(min_temp * nums[i], nums[i]);
            max_product = max(max_product, max_temp);
        }
        return max_product;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(-3);  
    nums.push_back(-1);
    nums.push_back(-1);
    Solution* ss = new Solution();
    int result = ss->maxProduct(nums);
    cout << result;
}