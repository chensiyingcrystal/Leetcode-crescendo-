#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        //first fold the matrix against the horizontal center line
        const int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[m - 1 - i][j]);
            }
        }

        //then fold against the diagonal line (from left to right)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > i) swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;

    }
};