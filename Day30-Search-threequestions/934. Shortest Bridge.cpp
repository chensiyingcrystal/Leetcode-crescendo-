#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
//这是一个找最短距离的问题
//break成子问题：先找第一个岛 + 标记 + 从标记的所有点出发
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    int shortestBridge(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        //search one island first using dfs; mark this island 2 for all points
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (flag == false) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n);
                    flag = false;
                    break;
                }
            }
        }

        //begin bfs search from the first_island
        int level = 0;
        vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int> > q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
            
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            
            for (int x = 0; x < 4; x++) {
                int new_i = tmp.first + row[x];
                int new_j = tmp.second + col[x];
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
                if (visited[new_i][new_j] != -1) continue;
                
                q.push(make_pair(new_i, new_j));
                visited[new_i][new_j] = visited[tmp.first][tmp.second] + 1;
                if (grid[new_i][new_j] == 1) {
                    return  visited[new_i][new_j] - 1;
                }
            }
        }

        return 0;
    }

    void dfs(vector<vector<int> >& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2) return;
        if (grid[i][j] == 0) return;
        grid[i][j] = 2;
        for (int x = 0; x < 4; x++) {
            int new_i = i + row[x];
            int new_j = j + col[x];
            dfs(grid, new_i, new_j, m, n);
        }
    }

//自己重新写一遍
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    int shortestBridge(vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size();
        //find the first island, mark each of them as 2
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (flag == false) break;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n);
                    flag = false;
                    break;
                }
            }
        }

        //Now we have found all first land with them marked as 2
        //begin our bfs
        //our result and visited container are one
        //visited represent distance from the first island
        //set the first island in visited as 0; initialize the queue
        queue<pair<int, int> > q;
        vector<vector<int> > visited(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();

            if (grid[tmp.first][tmp.second] == 1) return visited[tmp.first][tmp.second] - 1;

            for (int x = 0; x < 4; x++) {
                int new_i = tmp.first + row[x];
                int new_j = tmp.second + col[x];
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
                if (visited[new_i][new_j] != -1) continue;

                visited[new_i][new_j] = visited[tmp.first][tmp.second] + 1;
                q.push({new_i, new_j});
            }
        }

        return 0;
    }

    void dfs(vector<vector<int> >& grid, int i, int j, int m, int n) {
        //the index must be in the scope
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        //the point not be visited and the point must be part of the island
        if (grid[i][j] == 2 || grid[i][j] == 0) return;

        //entering into the point and mark it as 2; push it into the queue
        grid[i][j] = 2;
        //start searching its neighbors
        for (int x = 0; x < 4; x++) {
            int new_i = i + row[x];
            int new_j = j + col[x];
            //bug: new_i, new_j instead of i, j
            dfs(grid, new_i, new_j, m, n);
        }
    }
};

