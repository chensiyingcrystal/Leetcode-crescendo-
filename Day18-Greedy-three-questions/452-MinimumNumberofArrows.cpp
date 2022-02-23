#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
    //类似题435，按结尾排序最快捷
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>&b) {
            return a[1] < b[1];
        });
        vector<int> prev = points[0];
        int count = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > prev[1]) {
                count++;
                prev = points[i];
            } 
        }
        return count;
    }
    //按开头排序的话，考虑特殊情况，谁的ending小取谁（跟ending小的有重复肯定跟ending大的重复）
    //不要把问题想太复杂，要抓住事物本质和原理；如果这样实在写不出来就及时换种思路做，比如结尾
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> prev = points[0];
        int count = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > prev[1]) {
                count++;
                prev = points[i];
            } 
            else {
                if (points[i][1] <= prev[1]) {
                    prev = points[i];
                }
            }
        }
        return count;
    }
};