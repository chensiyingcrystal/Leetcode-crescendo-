#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int maxArea(vector<int>& height) {
        
        return 0;
    }

};


int main() {
    vector<int> nums;
    nums.push_back(1);  
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(3);
    nums.push_back(7);
    Solution* ss = new Solution();
    int result = ss->maxArea(nums);
    cout << result;
}