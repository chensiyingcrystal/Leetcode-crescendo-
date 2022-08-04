#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMinMerge(vector<vector<int> >& intervals) {
        int minMerge = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            else {
                return a[1] < b[1];
            }
        });

        vector<int> temp = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= temp[1]) {
                temp = intervals[i];
            }
            else {
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
                minMerge++;
            }
        }
        return minMerge;
    }

};