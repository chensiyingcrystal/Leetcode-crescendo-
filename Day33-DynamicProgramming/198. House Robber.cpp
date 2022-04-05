#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int odd_sum = 0, even_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) even_sum += i;
            else odd_sum += i;
        }
        return max(odd_sum, even_sum);
    }
};