#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        //special case
        if (intervals.size() == 1) return {intervals[0]};
        //sort the intervals by their first number in increasing order
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        //begin looping through intervals
        vector<int> prev = intervals[0];
        vector<vector<int> > merged;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > prev[1]) {
                //not merging, push prev into our result
                merged.push_back(prev);
                prev = intervals[i];
            }
            else {
                //merging two intervals
                vector<int> merged_intervals = {min(prev[0], intervals[i][0]), max(prev[1], intervals[i][1])};
                prev = merged_intervals;
            }
        }
        //important: remember to double-check the result befor submitting
        merged.push_back(prev);
        return merged;
    }
        
};