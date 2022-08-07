#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMinDistanceRemoveObstacle(vector<vector<int> > grid) {
        int n = grid.size(); //3
        int m = grid[0].size(); //3
        queue<int> q;
        q.push(0);// [0]
        grid[0][0] = INT_MAX; // T|0|0|
                              // 1|0|0|
                              // 1|9|1|
        int row[4] = {0, 0, 1, -1};
        int col[4] = {1, -1, 0, 0};
        int distance = 0;

        while (!q.empty()) {
            int size = q.size();//1
            while (size--) {//size->0
                int pos = q.front();//pos -> 0
                q.pop();//q: []
                int i = pos / m, j = pos % m;//i-> 0, j->0
                for (int x = 0; x < 4; x++) {//x->0
                    int new_i = i + row[x];//new_i -> 0
                    int new_j = j + col[x];//new_j -> 0
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] != INT_MAX && grid[new_i][new_j] != 0) {
                        if (grid[new_i][new_j] == 9) return distance + 1;
                        if (grid[new_i][new_j] == 1) {
                            q.push(new_i * m + new_j);
                            grid[new_i][new_j] = INT_MAX;
                        }
                    }
                }
            }
            distance++;
        }
        return -1;  
    }

        

    

};

int main() {
    Solution* ss = new Solution();
    vector<vector<int> > grid = {{1, 0, 0}, {1, 0, 0}, {1, 9, 1}};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << '|';
        }
        cout << '\n';
    }

    int pos = ss->findMinDistanceRemoveObstacle(grid);
    cout << pos << endl;
    return 0;
}