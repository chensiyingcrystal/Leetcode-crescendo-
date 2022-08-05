#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    Solution() {

    }

    int findMaxGreyness(vector<vector<int> >& grid) {
        //if (grid.size() == 0) return 0;
        int maxGrey = INT_MIN;
        int n = grid.size(), m = grid[0].size();
        //initialzie two vectors to store the number of white cells for each row and col
        vector<int> whiteRow(n, 0);
        vector<int> whiteCol(m, 0);
        //loop through the grid and calculate white cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    whiteRow[i] += 1;
                    whiteCol[j] += 1;
                }
            }
        }
        //loop through the grid and calcualte max greyness
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxGrey = max(maxGrey, m + n - 2 * (whiteRow[i] + whiteCol[j]));
            }
        }
        return maxGrey;
    }



};