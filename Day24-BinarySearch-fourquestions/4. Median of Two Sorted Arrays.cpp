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
//学习这个问题的巧妙解法：应用至找两个数组甚至多个数组的TOP K元素中
//time: 每次进入循环，排除掉k/2的元素，所以时间复杂度是o(logk), k = (m + n) / 2
//利用的递归原理：元素最后都会在k=1或者短数组变空的时候收敛
//空间复杂度：虽然我们用到了递归，但是可以看到这个递归属于尾递归，所以编译器不需要不停地堆栈，所以空间复杂度为 O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //before calling the helper function, we need to make sure what is k based on the odd/even case
        int n = nums1.size();
        int m = nums2.size();
        int left = (m + n) / 2;
        int right = (m + n) / 2 + 1;
        if ((m + n) % 2 == 0) {
            return (findKMostElement(nums1, 0, n - 1, nums2, 0, m - 1, left) 
                    + findKMostElement(nums1, 0, n - 1, nums2, 0, m - 1, right)) / 2;
        }
        else {
            return findKMostElement(nums1, 0, n - 1 , nums2, 0, m - 1, right);
        }
        
    }

    //define a helper function to find k most element
    double findKMostElement(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        //define the length of the new nums(use pointers to represent our created nums)
        int length1 = end1 - start1 + 1;
        int length2 = end2 - start2 + 1;
        //make sure length 1 is the first to be empty
        if (length1 > length2) return findKMostElement(nums2, start2, end2, nums1, start1, end1, k);
        //base case: either nums1 is empty or k equals to 1
        if (length1 == 0) return nums2[start2 + k - 1];
        if (k == 1) return min(nums1[start1], nums2[start2]);
        //begin recursion
        int new_start1 = start1 + k / 2 - 1;
        int new_start2 = start2 + k / 2 - 1;
        if (new_start1 >= nums1.size()) {
            new_start1 = nums1.size() - 1;
        }

        if (nums1[new_start1] <= nums2[new_start2]) {
            k = k - (new_start1 - start1 + 1);
            return findKMostElement(nums1, new_start1 + 1, end1, nums2, start2, end2, k);
        }
        else {
            k = k - (new_start2 - start2 + 1);
            return findKMostElement(nums1, start1, end1, nums2, new_start2 + 1, end2, k);
        }
    }
};