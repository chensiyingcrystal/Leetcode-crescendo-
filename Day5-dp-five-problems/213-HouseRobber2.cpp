#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int rob(vector<int>& nums) {
        
    }

}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    Solution* ss = new Solution();
    int result = ss->rob(nums);
    cout << result << endl;
    return 0;
}