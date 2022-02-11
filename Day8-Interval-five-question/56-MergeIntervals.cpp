#include <iostream>
#include <unordered_map>
#include <vector>

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
             [](vector<int> a, vector<int> b){
                    return a[0] < b[0];
                });
        vector<vector<int> > ans;
        // if current.start <= last.end: Merge intervals(two cases: last.end > curren.end or <)
        // else: Insert a new interval
        for(const auto& interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
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