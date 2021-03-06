#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <queue>


using namespace std;


class Solution {
public:
//hard, not understand
    vector<vector<int> > getSkyline(vector<vector<int> >& buildings) {
        vector<vector<int> > ans;
        //default pq, pair(height, right point), default compare:
        //first value larger on the top, if first value equals, then compare the second one
        priority_queue<pair<int, int> > max_heap;
        int cur_x, cur_h;
        int i = 0;
        while (!max_heap.empty() || i < buildings.size()) {
            //if pq is empty or the element's right point is less than the highest block's right point
            //continue to add blocks unless the block is out of the top one's right boundary
            if (max_heap.empty() || i < buildings.size() && buildings[i][0] <= max_heap.top().second) {
                cur_x = buildings[i][0];
                //special case: several blocks with same left boundary but different height
                //we only record the highest one's left point
                while (i < buildings.size() && buildings[i][0] == cur_x) {
                    //construct value in place instead of copy an already created value using push
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    i++;
                }
            }
            //else: digest what on the left side of the top one's right boundary
            else {
                cur_x = max_heap.top().second;
                //pop out blocks that are at the left bottom side of the top block
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }

            //record, if the highest block already exists in the answer, do not record it
            cur_h = max_heap.empty()? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }
        }
        return ans;
    }

};