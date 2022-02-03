#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int maxProduct(vector<int>& nums) {
        int product = 1;
        int maxProduct = INT_MIN;
        int minProduct = 1;
        for(int i = 0; i < nums.size(); i++) {
            product *= nums[i];

            if(product > 0 and minProduct < 0) {
                maxProduct = max(maxProduct, product);
            }
            else { 
                maxProduct = max(maxProduct, product / minProduct);
            }

            if(product < minProduct and product > 0) {
                minProduct = product;
            }
        }
        return maxProduct;
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