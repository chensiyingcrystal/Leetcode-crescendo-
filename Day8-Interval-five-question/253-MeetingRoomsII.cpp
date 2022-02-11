#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    bool canAttendMeetings(vector<vector<int> >& intervals) {
        if (intervals.size() == 1 || intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        vector<int> comparing = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= comparing[1]) comparing = intervals[i];
            else { return false; }
        }
        return true; 
    }

};


int main() {
    return 0;
}