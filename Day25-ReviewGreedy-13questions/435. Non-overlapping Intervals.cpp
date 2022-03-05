#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        //special case
        if (intervals.size() == 1) return 0;
        //sort based on the ends of intervals
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        //loop through intervals to see how many of them should be removed?
        int removed = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prev[1]) {
                removed++;
            }
            else {
                prev = intervals[i];
            }
        }

        return removed;
    }

};