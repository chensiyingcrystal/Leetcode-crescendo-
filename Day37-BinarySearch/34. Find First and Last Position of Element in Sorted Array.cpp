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
//自己写的第一遍代码
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
//改进版代码
//-将重复代码封入一个function，用boolean值判断要寻找第一个还是最后一个出现的index
//将同类型的代码逻辑整合
//-改进变量名称
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        const int n = nums.size();
        int start = helper(nums, target, n, true);

        if (start == -1) return {-1, -1};

        int end = helper(nums, target, n, false);
        return {start, end};
    }

    int helper(vector<int>& nums, int target, int n, bool flag) {
        int pos = -1;
        int left = 0, right = n - 1;
        //add empty line indicating logic section
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                //the value of flag determines the options we will perform 
                //if it's true, we're finding the start position of the value of target
                //else, we're finding its end position
                if (flag) {
                    //two cases that indicating the mid element is the start position
                    if (mid == left || nums[mid - 1] < target) {
                        pos = mid;
                        return pos;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                else {
                    if (mid == right || nums[mid + 1] > target) {
                        pos = mid;
                        return pos;
                    }
                    else {
                        left = mid + 1;
                    }
                }
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return pos;
    }
//自己写的第三遍
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return {-1, -1};
        //建议增加对于一个元素的检查

        //search left boundary
        int leftbound = searchBoundary(nums, target, true);

        //if not found, return {-1, -1}
        if (leftbound == -1) return {-1, -1};

        //else, search right boundary
        int rightbound = searchBoundary(nums, target, false);
        
        return {leftbound, rightbound};
    }

    int searchBoundary(vector<int>& nums, int target, bool flag) {
        //尽量添加此变量
        const int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (flag) { // indicating we're finding left boundary
                //bug！！！凡是这样类型的index一定注意有没有overflow
                    if (mid >= 1 && nums[mid - 1] == nums[mid]) {
                        right = mid - 1;
                    }
                    else return mid;
                }
                else { // indicating we're finding right boundary
                //bug！！！凡是这样类型的index一定注意有没有overflow
                    if (mid <= n - 2 && nums[mid + 1] == nums[mid]) {
                        left = mid + 1;
                    }
                    else return mid;
                }
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            } 
        }
        return -1;
    }
//用right-left>1写出来的版本
//特点：不用去考虑nums[mid] == target的单独的情况，将其包含在left或者right一侧
//要做post-processing，对最后剩下的两个端点进行考虑；需要思考一下post-processing对只有两元素（无法进入循环）的情况进行考虑是否适用
        vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return {-1, -1};

        //search left boundary
        int leftbound = searchBoundary(nums, target, true);

        //if not found, return {-1, -1}
        if (leftbound == -1) return {-1, -1};

        //else, search right boundary
        int rightbound = searchBoundary(nums, target, false);
        
        return {leftbound, rightbound};
    }

    int searchBoundary(vector<int>& nums, int target, bool flag) {
        const int n = nums.size();      
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (flag) {
                if (nums[mid] >= target) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            else {
                if (nums[mid] <= target) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
        }
        if (flag) {
            if (nums[left] == target) return left;
            else if (nums[right] == target) return right;
            return -1;    
        }
        else {
            if (nums[right] == target) return right;
            else if (nums[left] == target) return left;
            return -1;
        }
        return -1;
    }
};