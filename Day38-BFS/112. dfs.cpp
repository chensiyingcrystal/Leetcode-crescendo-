#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int findPath(vector<vector<int> >& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int path = 0;
        for (int i = m - 1, j = 1; j < n; j += 2) {
            dfs(grid, i, j, m, n, path);
        }
        return path;
    }

    void dfs(vector<vector<int> >& grid, int i, int j, int m, int n, int& path) {
        if (i < 0 || j < 0 || j >= n) return;
        if (i == 0) {
            path += 1;
        }

        dfs(grid, i - 1, j - 1, m, n, path);
        dfs(grid, i - 1, j + 1, m, n, path);
    }

};

int main() {
    vector<vector<int> > grid(8, vector<int>(8, 0));
    Solution* ss = new Solution();
    int path = ss -> findPath(grid);
    cout << path << endl;
}
