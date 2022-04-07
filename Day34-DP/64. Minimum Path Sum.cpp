#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> sums;
        int tmp;
        backtrack(grid, 0, 0, tmp, sums);
        int ans = INT_MAX;
        for (int i = 0; i < sums.size(); i++) {
            ans = min(sums[i], ans);
        }
        return ans;
    }

    void backtrack(vector<vector<int> >& grid, int i, int j, int& tmp, vector<int>& sums) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            tmp += grid[i][j];
            sums.push_back(tmp);
            tmp -= grid[i][j];
            return;
        }

        tmp += grid[i][j];
        if (i + 1 < grid.size()) backtrack(grid, i + 1, j, tmp, sums);
        if (j + 1 < grid[0].size()) backtrack(grid, i, j + 1, tmp, sums);
        tmp -= grid[i][j];
    }

    int minPathSum(vector<vector<int> >& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        

    }
};