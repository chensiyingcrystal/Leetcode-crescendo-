#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {


   }

// solution2
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;
        int start_r = 0;
        int start_c = 0;
        while(m > 0 && n > 0) {
            for(int j = 0; j < n; j++) spiral.push_back(matrix[start_r][start_c + j]);
            for(int i = 1; i < m; i++) spiral.push_back(matrix[start_r + i][start_c + n - 1]);
            if (m >= 2) {
                for(int j = n - 2; j >= 0; j--) spiral.push_back(matrix[start_r + m - 1][start_c + j]);
            }
            if (n >= 2) {
                for(int i = m - 2; i >= 1; i--) spiral.push_back(matrix[start_r + i][start_c]);
            }
            m = m - 2;
            n = n - 2;
            start_r += 1;
            start_c += 1;
        }
        return spiral;
    }

// solution1
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;
        int start_r = 0;
        int start_c = 0;
        while(m > 0 && n > 0) {
            for(int j = start_c; j <= start_c + n - 1; j++) spiral.push_back(matrix[start_r][j]);
            for(int i = 1 + start_r; i <= start_r + m - 1; i++) spiral.push_back(matrix[i][start_c + n - 1]);
            if (m >= 2) {
                for(int j = start_c + n - 2; j >= start_c; j--) spiral.push_back(matrix[start_r + m - 1][j]);
            }
            if (n >= 2) {
                for(int i = start_r + m - 2; i >= 1 + start_r; i--) spiral.push_back(matrix[i][start_c]);
            }
            m = m - 2;
            n = n - 2;
            start_r += 1;
            start_c += 1;
        }
        return spiral;
    }


};


int main() {
    return 0;
}