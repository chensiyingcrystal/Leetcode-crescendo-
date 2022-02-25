#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//最初：不会解，卡壳原因：while的边界条件怎么定义？
    void merger(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mer(m + n, 0);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                mer.push_back(nums1[i]);
                i++;
            }
            else {
                mer.push_back(nums2[j]);
                j++;
            }
        }
        if (i == 0 && m == 0) {
            
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