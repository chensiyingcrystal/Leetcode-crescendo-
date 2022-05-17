#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
//brute force method: exceed tl
//if at ith digits, there are n words, among which c words has 1, and n - c has 0
//then the total hamming distance for these words is c * (n-c)(the total combination number)
//loop through each digits
    int totalHammingDistance(vector<int>& nums) {
        //!!!!must initialize!!!since you'll use ans +=!!!
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= 31; i++) {
            int count = 0;
            for (int& num : nums) {
                count += (num >> i) & 1;
            }
            ans += count * (n - count);
        }
        return ans;   
    }

};