#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int findMin(vector<int>& nums) {
        
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