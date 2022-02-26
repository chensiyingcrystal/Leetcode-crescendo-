#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//最初：用了两个指针但是不会解，卡壳原因：while的边界条件怎么定义？
//破解：加入第三个指针，writing pointer, 用第三个指针控制条件
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mer(m + n, 0);
        int i = 0, j = 0, k = 0;
        while (k < m + n) {
            if (i >= m) {
                for (int x = j; x < n; x++) {
                    mer[k] = nums2[x];
                    k++;
                }
            }
            else if (j >= n) {
                for (int x = i; x < m; x++) {
                    mer[k] = nums1[x];
                    k++;
                }
            }
            else {
                if (nums1[i] <= nums2[j]) {
                    mer[k] = nums1[i];
                    i++;
                }
                else {
                    mer[k] = nums2[j];
                    j++;
                }
                k++;
            }
        }
        
        for (int i = 0; i < m + n; i++) {
            nums1[i] = mer[i];
        }

        return;

    } 
//自己写的代码进行简化
//time: o(n+m), space: o(n+m)，不是最优代码，因为复制整个vector也需要时间
//复制整个vector之前，思考有没有可以复制更少的情况，或者不复制就能进行的情况
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mer(m + n, 0);
        int i = 0, j = 0, k = 0;
        while (k < m + n) {
            //four种情况：i未超j超出，i超出j未超，ij均未超出且nums1小，ij均未超出且nums2小
            //如果j超出了界限，或者j没有超出界限; 边界条件太复杂的时候想下能否先确定类型，根据逻辑将其合并为几种情况
            //根据题意，j超出的时候，i肯定没有超出，所以前面不需要写i<m
            if (j >= n || i < m && nums1[i] <= nums2[j]) {
                mer[k] = nums1[i++];
            }
            else {
                mer[k] = nums2[j++];
            }
            k++;
        }
        
        for (int i = 0; i < m + n; i++) {
            nums1[i] = mer[i];
        }
    } 
//可以将o(n+m)空间缩减为o(m)
//做法：先复制m长度的数组，然后在原来nums1的数组中修改
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy(m);
        for (int i = 0; i < m; i++) {
            nums1_copy[i] = nums1[i];
        }

        int i = 0, j = 0, k = 0;
        while (k < m + n) {
            if (j >= n || i < m && nums1_copy[i] <= nums2[j]) {
                nums1[k++] = nums1_copy[i++];
            }
            else {
                nums1[k++] = nums2[j++];
            }
        }
    } 
//不需要额外空间的办法：两指针从各自末尾，一指针从总的末尾
//这种方法控制条件是由另外两支指针控制，巧妙的是如果出现没复制完的情况，将n没复制完的情况考虑即可
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //用m和n充当指针
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0) {
            nums1[pos--] = nums1[m] >= nums2[n] ？ nums1[m--] : nums2[n--];
        }
        //退出上述循环的条件是m到头或者n到头，如果是m到了头，要记得将n复制进去
        //反之如果是n到了头，前面的已排好序，m不用调整
        while (n >= 0) {
            nums1[pos--] = nums2[n--];
        }
    }
//取巧的办法（没有用双指针）：merger and sort
//time: o((n+m)log(n+m)), space o(n)(sorting: recursion depth)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  )
};