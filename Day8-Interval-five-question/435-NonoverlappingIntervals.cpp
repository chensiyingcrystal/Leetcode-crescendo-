#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        // special case
        if (intervals.empty() || intervals.size() == 1) return 0;
        int remove = 0;
        // reference instead of value, which will increase time
        sort(intervals.begin(), intervals.end(), 
              [](vector<int>& a, vector<int>& b) {
                  return a[0] < b[0];
              });
        vector<int> comparing = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < comparing[1]) {
                remove += 1;
                if (intervals[i][1] <= comparing[1]) {
                    comparing = intervals[i];
                }
            }
            else { 
                comparing = intervals[i];
            }
        }
        return remove;
    }

};


int main() {
    return 0;
}