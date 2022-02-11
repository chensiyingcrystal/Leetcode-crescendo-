#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
   Solution() {

   }

// min-heap and priority queue
   int minMeetingRooms(vector<vector<int> >& intervals) {
        if (intervals.empty()) return 0;
        if (intervals.size() == 1) return 1;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int> > min_heap;
        min_heap.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= min_heap.top()) {
                min_heap.pop();
            }
            min_heap.push(intervals[i][1]);
        }
        return min_heap.size();
    }
};


int main() {
    return 0;
}