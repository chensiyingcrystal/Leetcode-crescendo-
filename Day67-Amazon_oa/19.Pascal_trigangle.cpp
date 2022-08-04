#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    string getEncryptedNumber(vector<int>& nums) {
        int n = nums.size();
        for (int end = n - 1; end > 1; end--) {
            for (int start = 0; start < end; start++) {
                nums[start] = (nums[start] + nums[start + 1]) % 10;
            }
        }
        return to_string(nums[0]) + to_string(nums[1]);
    }
};

int main() {
    Solution* ss = new Solution();
    vector<int> stock = {4, 5, 6, 7};
    string pos = ss->getEncryptedNumber(stock);
    cout << pos << endl;


}