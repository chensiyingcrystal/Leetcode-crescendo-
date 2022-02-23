#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//第一遍问题：用两个循环加标记，没搞清楚循环的原理：对于已经排好序的情况，想想还需要用两次循环吗？
//问题2:按照开头排序，漏考虑了一种情况，被remove的不一定总是开头在后的那个；画图的时候想当然，逻辑不严密
//区间问题一定要考虑开头结尾的变化！！注意包含的特殊情况！！
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if (intervals.size() < 2) return 0;
        //preprocessing sort：默认按照开头排序
        sort(intervals.begin(), intervals.end());
        //looping
        int ans = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev[1]) {
                ans++;
                if (intervals[i][1] < prev[1]) {
                    prev = intervals[i];
                }
            }
            else {
                prev = intervals[i];
            }
        }
        return ans;
    }
//另一种解法：按照结尾排序
   int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        //不加&就会超时
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
           return a[1] < b[1];
           });
        vector<int> remove = intervals[0];
        //bug: 不赋初始值会出错，人为赋值不会错
        int ans = 0;
        //bug：i从1开始
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < remove[1]) {
                ans++;
            }
            else {
                remove = intervals[i];
            }
        }
        return ans;   
   }
};