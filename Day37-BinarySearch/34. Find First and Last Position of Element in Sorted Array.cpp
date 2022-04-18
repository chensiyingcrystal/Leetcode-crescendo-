#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
   vector<int> searchRange(vector<int>& nums, int target) {
       if (nums.empty()) return {-1, -1};
       const int n = nums.size();
       int left1 = 0, right1 = n - 1;
       //set the variable name as begin and end
       int l = INT_MAX;
       while (left1 <= right1) {
           int mid1 = left1 + (right1 - left1) / 2;
           if (nums[mid1] == target) {
               if (mid1 == 0) {
                   l = mid1; 
                   break;
               }
               else {
                   if (nums[mid1 - 1] == target) {
                       right1 = mid1 - 1; //
                   }
                   else {
                       l = mid1;
                       break;
                   }
               }
           }
           else if (nums[mid1] > target) {
               right1 = mid1 - 1;
           }
           else {
               left1 = mid1 + 1;
           }
       }
       if (l == INT_MAX) return {-1, -1};
       int r;
       int left2 = 0, right2 = n - 1;
       while (left2 <= right2) {
           int mid2 = left2 + (right2 - left2) / 2;
           if (nums[mid2] == target) {
               if (mid2 == n - 1) {
                   r = n - 1;
                   return {l, r};
               }
               else {
                   if (nums[mid2 + 1] == target) {
                       left2 = mid2 + 1;
                   }
                   else {
                       r = mid2;
                       return {l, r};
                   }
               }
           }
           else if (nums[mid2] > target) {
               right2 = mid2 - 1;
           }
           else {
               left2 = mid2 + 1;
           }
       }
       return {l, r};
   }
};