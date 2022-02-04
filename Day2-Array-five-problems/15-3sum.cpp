#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
//Two Pointers
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int> > output;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            int target = - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < target) ++j;
                else if (nums[j] + nums[k] > target) --k;
                else {
                    output.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    ++j; --k;
                }

            }
        }
        return output;
    }


//Wrong Solution
    // vector<vector<int> > twoSum(vector<int>& nums, int target, int n) {
    //     vector<vector<int> > all;
    //     unordered_map<int, int> output;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(i != n) {
    //             int complement = target - nums[i];
    //             if(output.count(complement) and output[complement] != i) {
    //                 all.push_back({output[complement], i});
    //             }
    //             else {
    //                 output[nums[i]] = i;
    //             }
    //         }
    //     }
    //     return all;
    // }

    // vector<vector<int> > threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) {
    //         return {};
    //     }

    //     vector<vector<int> > output;
    //     for(int i = 0; i < nums.size(); i++) {
    //         int target = 0 - nums[i];
    //         vector<vector<int> > other_two = twoSum(nums, target, i);
    //         if (other_two.size() != 0) {
    //             for(int j = 0; j < other_two.size(); j++) {
    //                 vector<int> answer;
    //                 if ((i < other_two[j][0]) && (other_two[j][0] < other_two[j][1])) {
    //                     if ((j == 0) or (j >= 1 && other_two[j][0] != other_two[j-1][0] && other_two[j][1] != other_two[j-1][1])) {
    //                         answer.push_back(nums[i]);
    //                         answer.push_back(nums[other_two[j][0]]);
    //                         answer.push_back(nums[other_two[j][1]]);
    //                         output.push_back(answer);
    //                     }
    //                 }
    //             } 
    //         }
    //     }
    //     return output;
    // }


};


int main() {
    vector<int> nums;
    nums.push_back(-1);  
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    Solution* ss = new Solution();
    vector<vector<int> > result = ss->threeSum(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
    }
}