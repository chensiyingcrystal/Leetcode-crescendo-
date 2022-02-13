#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {


   }

    void rotate(vector<vector<int> >& matrix) {
        // fold against diagonal(i + j = n)
            // scope: i + j < n - 1
            // swap: i' = n - 1 - j, j'= n - 1 - i
        if (matrix.empty()) return;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j < n - 1) {
                    int new_i = n - 1 - j;
                    int new_j = n - 1 - i;
                    int tmp = matrix[new_i][new_j];
                    matrix[new_i][new_j] = matrix[i][j];
                    matrix[i][j] = tmp;
                }
            }
        }
        // fold against middle axis
            // scope: i <= n / 2
            // swap: j不变，i' = n - 1 - i
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = 0; j < n; j++) {
                int new_i = n - 1 - i;
                int tmp = matrix[new_i][j];
                matrix[new_i][j] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        return;     
    }


};


int main() {
    cout << 3 / 2 << endl;
    return 0;
}