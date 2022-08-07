#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

class Solution {

public:
    Solution() {

    }

    int findRemainderPair(vector<int>& nums) {
        //calculate num%60 and its frequency
        unordered_map<int, int> freq;
        for (int& num : nums) {
            freq[num % 60]++;
        }
        //calculate total pairs that sum up to 60
        int ans = 0;
        for (auto& pair : freq) {
            if (pair.first == 0 || pair.first == 30) {
                ans += pair.second * (pair.second - 1) / 2;
            }
            else {
                if (freq.count(60 - pair.first) && pair.first < 60 - pair.first) {
                    ans += pair.second * freq[60 - pair.first];
                }
            }
        }
        return ans;
    }

};

int main() {
    vector<int> nums = {30, 20, 150, 100, 40};
    Solution* ss = new Solution();
    int temp2 = ss->findRemainderPair(nums);
    cout << temp2 << endl;

    vector<int> nums2 = {30, 30, 30};
    int temp3 = ss->findRemainderPair(nums2);
    cout << temp3 << endl;
    return 0;
    
}

