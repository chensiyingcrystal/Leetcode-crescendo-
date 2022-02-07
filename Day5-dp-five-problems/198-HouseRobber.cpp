#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int rob(vector<int>& nums) {
        const int n = nums.size();
        vector<int> rob(n + 2);
        for(int i = 0; i < n; ++i) {
            rob[i + 2] = rob[i] + nums[i];
        }
        int result = 0;
        for(auto r : rob) result = max(result, r);
        return result;   
    }


}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    Solution* ss = new Solution();
    int result = ss->rob(nums);
    cout << result << endl;
    return 0;
}