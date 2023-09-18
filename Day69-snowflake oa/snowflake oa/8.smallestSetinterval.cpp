#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

//题目：https://www.1point3acres.com/bbs/thread-1003866-1-1.html
    int interval(vector<int>& start, vector<int>& end) {
        vector<vector<int>> intervals;
        for (int i = 0; i < start.size(); i++) {
            intervals.push_back({start[i], end[i]});
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });

        vector<int> res;
        res.push_back(intervals[0][1] - 1);
        res.push_back(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start <= res[res.size() - 2]) {
                continue;
            } else if (start <= res[res.size() - 1]) {
                res.push_back(end);
            } else {
                res.push_back(end - 1);
                res.push_back(end);
            }
        }
        return res.size();
        
    }

};

int main() {
    Solution* ss = new Solution();
    vector<int> start = {0, 1, 2};
    vector<int> end = {2, 3, 3};
    int res = ss->interval(start, end);
    cout << res << endl;

    return 0;


}