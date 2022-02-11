#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        bool added = false;
        for(int i = 0; i < intervals.size(); ++i) {
            if (newInterval[1] < intervals[i][0]) {
                if (!added) {
                    ans.push_back(newInterval);
                    added = true;
                }
                ans.push_back(intervals[i]);
            }
            else if (newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
                if (i == intervals.size() - 1) ans.push_back(newInterval);
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                if (i == intervals.size() - 1) ans.push_back(newInterval);
            }
        }
        return ans;
    }

};


int main() {
    return 0;
}