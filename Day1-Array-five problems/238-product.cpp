#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        int product = 1;
        for(int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            prefix.push_back(product);
        }
        
        vector<int> suffix;
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            suffix.push_back(product);
        }
        
        vector<int> output;
        const int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                output.push_back(suffix[n - i - 2]);
            }
            else if(i == n - 1) {
                output.push_back(prefix[i - 1]);
            } 
            else {
                output.push_back(prefix[i - 1] * suffix[n - i - 2]);
            }
        }

        return output;
        
    }

};


int main() {
    vector<int> nums;
    nums.push_back(-1);  
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-3);
    nums.push_back(3);
    Solution* ss = new Solution();
    vector<int> result = ss->productExceptSelf(nums);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}