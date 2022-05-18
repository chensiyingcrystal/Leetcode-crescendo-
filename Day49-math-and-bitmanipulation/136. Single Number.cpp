#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            ans  = ans ^ num;
        }
        return ans;
    }

};