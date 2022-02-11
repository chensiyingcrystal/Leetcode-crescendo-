#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        // special case
        if (newInterval.empty()) return intervals;
        // begin loop
        for(int i = 0; i < intervals.size(); i++) {
            if (start <= intervals[i][0])

        }
        
    }

};


int main() {
    return 0;
}