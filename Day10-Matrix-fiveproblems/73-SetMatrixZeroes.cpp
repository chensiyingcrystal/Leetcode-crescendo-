#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {


   }

    void setZeroes(vector<vector<int> >& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        int cross = 1;

        // loop to find zero and set 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) cross = 0;
                    else matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // priority: main part(i = 1 to m-1, j = 1 to n-1) -> zero column(j=0) -> zero row(i =0)
        // loop through marked row and column and set 
        // if use auto remember to put &!! 否则修改的只是x的值！！！
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // loop through zero column
        if (matrix[0][0] == 0) {
            for(int i = 1; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        // set zero row
        if (cross == 0) {
            for (int j = 1; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // optimized edition: traversing in the diverse direction
        for(int j = n - 1; j >= 0; --j) {
            for (int i = m - 1; i >= 1; --i) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (cross == 0) matrix[0][j] = 0;
        }
        
        return;
    }


};


int main() {
    return 0;
}