#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

class Solution {

public:
    Solution() {

    }

    int findMinDeliver(vector<int>& nums) {
        //sort nums
        sort(nums.begin(), nums.end());
        //calculate frequency of each weight
        unordered_map<int, int> freq;
        for (int& num : nums) {
            freq[num]++;
        }
        //calculate min delivery times based on each weight's frequency
        int ans = 0;
        for (auto& pair : freq) {
            int val = pair.second;
            if (val == 1) return -1;
            if (val % 3 == 0) ans += val / 3;
            else ans += val / 3 + 1;
        }
        return ans;
    }

};

int main() {
    vector<int> nums = {2, 4, 6, 6, 4, 2, 4};
    Solution* ss = new Solution();
    int temp2 = ss->findMinDeliver(nums);
    cout << temp2 << endl;

    vector<int> nums2 = {1, 2, 1};
    int temp3 = ss->findMinDeliver(nums2);
    cout << temp3 << endl;
    return 0;
    
}

