#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
//task: 1st is finding the transpose and second is reversing the columns without using extra space
//solving matrix problems: break into two transpose steps!!
//mindset: don't think how to transpose row by row, but cell by cell! just by swapping two!!
    void rotate(vector<vector<int> >& matrix) {
        //first fold the matrix against the horizontal center line
        const int m = matrix.size(), n = matrix[0].size();
        //bug：loop the whole matrix, thus resulting in no change at all
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