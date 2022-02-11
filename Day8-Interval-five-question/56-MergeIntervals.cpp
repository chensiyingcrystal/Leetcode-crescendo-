#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   Solution() {

   }

    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        // special case
        if (intervals.empty()) return {};
        // sorting: sort intervals by its start
        sort(intervals.begin(), intervals.end(), 
             [](const Interval& a, const Interval& b){
                    return a. start < b.start;
                });
        vector<Interval> ans;
        // if current.start <= last.end: Merge intervals(two cases: last.end > curren.end or <)
        // else: Insert a new interval
        for(const auto& interval : intervals) {
            if (ans.empty() || interval.start > ans.back().end) {
                ans.push_back(interval);
            }
            else {
                ans.back().end = max(ans.back().end, interval.end);
            }
        }
        return ans; 
    }
};


int main() {
    // initialize vector using array
    // int arr[] = {1, 2, 3};
    // vector<int> nums(begin(arr), end(arr));
    // for(int x : nums) {
    //     cout << x << endl;
    //
    return 0;
}