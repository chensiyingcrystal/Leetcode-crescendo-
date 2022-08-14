#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    Solution() {

    }

    int findMinDistanceToRemoveObstacle(vector<vector<int> > grid) {
        int distance = 0, m = grid.size(), n = grid[0].size();
        queue<int> q;
        q.push(0);
        grid[0][0] = INT_MAX; //marked as visited
        //directions row and cols
        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int temp = q.front();
                q.pop();
                //get the current cell's i and j
                int curr_i = temp / n;
                int curr_j = temp % n;
                //process its neighbor cells
                for (int x = 0; x < 4; x++) {
                    int new_i = curr_i + row[x];
                    int new_j = curr_j + col[x];
                    //if neightbor cells is in the boundary of grid and not visited
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] != INT_MAX) {
                        int cell = grid[new_i][new_j];
                        //if it's the obstacle, return the min distance
                        if (cell == 9) return distance + 1;
                        //if it's flat area, push it into the queue and marked as visited
                        if (cell == 1) {
                            q.push(new_i * n + new_j);
                            grid[new_i][new_j] = INT_MAX;
                        } 
                    }
                }
            }
            distance++;
        }

        return -1; //not found return -1
    }


    
};

int main() {
    Solution* ss = new Solution();
    vector<vector<int> > power = {{1, 0, 0}, {1, 0, 0}, {1, 9, 1}};
    int middleMax = ss->findMinDistanceToRemoveObstacle(power);
    cout << middleMax << endl;
    
    return 0;
}