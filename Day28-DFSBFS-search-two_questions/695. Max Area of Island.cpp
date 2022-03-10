#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size()));
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int area = 0;
                    dfs(grid, i, j, visited, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

    void dfs(vector<vector<int> >& grid, int i, int j, vector<vector<int> >& visited, int& area) {
        const int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        //bug: 忘记写grid[i][j] == 0
        if (grid[i][j] == 0 || visited[i][j]) return;

        visited[i][j] = 1;
        area += 1;
        dfs(grid, i + 1, j, visited, area);
        dfs(grid, i - 1, j, visited, area);
        dfs(grid, i, j + 1, visited, area);
        dfs(grid, i, j - 1, visited, area);
    }
        
};