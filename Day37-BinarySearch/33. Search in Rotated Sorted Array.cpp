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
    //自己写的第一遍代码，注意考虑array有无rotate的情况（k=0）
    int search(vector<int>& nums, int target) {
        //special case where nums has only one number
        const int n = nums.size();
        //----------need to simplify-----------
        if (n == 1) {
            if (target == nums[0]) return 0;
            else return -1;
        }
        //first find the index of the pivot
        if (nums[0] > nums[n - 1]) {
            int pivot = findPivot(nums, n);
            //compare target with the value of the pivot to decide which side it is in
            //----------need to simplify-----------
            if (target >= nums[0] && target <= nums[pivot]) {
                return binarySearch(nums, target, 0, pivot);
            }
            else if (pivot + 1 <= n - 1 && target >= nums[pivot + 1] && target <= nums[n - 1]) {
                return binarySearch(nums, target, pivot + 1, n - 1);
            }
        }
        else {
            //----------put this line of code before-----------
            return binarySearch(nums, target, 0, n - 1);
        }
        return -1;
    }

    int findPivot(vector<int>& nums, int n) {
        //----------add: if not rotated, return 0-----------
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
                //pivot must on the right side of mid
                left = mid;
            }
            else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
//简化后的代码
    int search(vector<int>& nums, int target) {
        //special case where nums has only one number
        const int n = nums.size();
        if (n == 1) {
            return target == nums[0] ? 0 : -1;
        }
        //if not rotated, search the entire array
        if (nums[0] < nums[n - 1]) {
            return binarySearch(nums, target, 0, n - 1);  
        }
        //find pivot for the rotated array
        int pivot = findPivot(nums, n);
            //compare target with the value of the pivot to decide which side it is in
        if (target >= nums[0]) {
            return binarySearch(nums, target, 0, pivot);
        }
        else {
            return binarySearch(nums, target, pivot + 1, n - 1);
        }
    }

    int findPivot(vector<int>& nums, int n) {
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
                //pivot must on the right side of mid
                left = mid;
            }
            else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return left;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
//one-pass
//这道题可以用一遍二分解决的原因在于
//使用二分将target逼入单调递增或者chasm的区域
//二分并非仅对于单调有序的数组可以做，如果此时有两段，一段有序，另一段无序也可以用一遍二分
//算法在于：each time we locate target to the ordered part, if it's not in there
    //we will discard the ordered part, thus converging the area continuously to the chasm
    //if the target is in the ordered part, this is the normal bs
    //if it's equal to the chasm, we will finally converge to that
    //for the left<=right modulate, we will get mid equal to the left or right, meaning they will
        //be visisted finally before the loop terminated
    //for the right-left > 1 case, we will finally converge to the chasm. 
        //then by adding some post-processing, we will find the target; if not, return -1;
    //if nothing is found, return -1
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        //Here we do not need to consider the case where nums has only one element
        //because in this case, mid will be equal to the left
        //and once the target not equal to the mid, it will be led to either one end increment by 1
        //the loop terminated and -1 is returned
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            //bug: mid might end up being equal to left, so must add "="
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
//改写成另一种
//前处理和后处理变多，但是代码主体基本相似，两种方式没有大的区别，甚至第一种更好
//此题在于寻找单个目标，因此前一种方式写起来会更加简单
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        //this method needs to consider special cases where nums has only one or two elements
        if (n == 1) return target == nums[0] ? 0 : -1;
        if (n == 2) {
            if (target == nums[0]) return 0;
            if (target == nums[1]) return 1;
            return -1;
        }

        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //this case can handle the situation where the nums has not been rotated
            //in this case it will always been led to this if-clause and bs been operated as usual
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
        }
        //The case will finally converge to the chasm
        //apart from the left or right, other elements have all been visited
        //so we need to do some post-processing
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};