// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); ++i) {
//             for(int j = i + 1; j < nums.size(); ++j) {
//                 int sum = nums[i] + nums[j];
//                 if (sum == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

// #include <iostream>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// class Solution {
// public:
//    Solution() {

//    }

//    vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> indies;
//         for (int i = 0; i < nums.size(); ++i) 
//             indies[nums[i]] = i;

//         for (int i = 0; i < nums.size(); ++i) {
//             int left = target - nums[i];
//             if (indies.count(left) && indies[left] != i) {
//                 return {i, indies[left]};
//             }
//         }

//         return {};
//     }
// };

// int main() {
//     vector<int> nums;
//     nums.push_back(3);  
//     nums.push_back(2);
//     nums.push_back(4);
//     Solution* ss = new Solution();
//     vector<int> result = ss->twoSum(nums, 6);
//     for (int i = 0; i < result.size(); i++) {
//         cout << result[i] << endl;
//     }
// }


//why unordered map?
// hash table
// key: 
// value:


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

   vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> output;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(output.count(complement) and i != output[complement]) {
                output.push_back(output[complement]);
                output.push_back(i);
                return output;
            }
            else {
                output[nums[i]] = i;
            }
        }

    }
};


int main() {
    vector<int> nums;
    nums.push_back(2);  
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(7);
    Solution* ss = new Solution();
    vector<int> result = ss->twoSum(nums, 9);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}