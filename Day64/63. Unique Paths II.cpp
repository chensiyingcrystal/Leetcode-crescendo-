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
//this question is pretty much like 62.unique path except adding some "obstacles" in the grid
//we'll still solve this kind of question using dynamic programming
//After adding obstacles, what we need to do is to check if the cell itself is an obstacle and if its neighbors are obstacle
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //special case: staring point is an obstacle
        if (obstacleGrid[0][0] == 1) return 0;
        obstacleGrid[0][0] = 1; //utilize input vector, decreasing extra space to o(1)
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //important: don't forget to check base case! Don't modify initial value!
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                }
                else {
                    obstacleGrid[i][j] += i >= 1? obstacleGrid[i - 1][j] : 0;
                    obstacleGrid[i][j] += j >= 1? obstacleGrid[i][j - 1] : 0;
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
        
    }
};