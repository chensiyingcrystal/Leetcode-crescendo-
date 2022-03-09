#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //copy nums1 into a new nums1
        vector<int> copied_nums1(m);
        for (int i = 0; i < m; i++) {
            copied_nums1[i] = nums1[i];
        }
        //use three pointers to loop through nums1 and update its merged value
        //i for copied_nums1, j for nums2, x for nums1
        int i = 0, j = 0, x = 0;
        while (i < m || j < n) {
            //这几个条件缺一不可
            if (j >= n || i < m && copied_nums1[i] <= nums2[j]) {
                nums1[x++] = copied_nums1[i++];
            }
            else {
                nums1[x++] = nums2[j++];
            }
        }
    }

//倒着写的
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //write merged value in reverse order(starting from m + n - 1)
        //set three pointer, i for the original nums1(starting at 0), j for nums2, x for "new" nums1
        int i = m - 1, j = n - 1, x = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (j < 0 || i >= 0 && nums1[i] >= nums2[j]) {
                nums1[x--] = nums1[i--]; 
            }
            else {
                nums1[x--] = nums2[j--];
            }
        }
    }     
};