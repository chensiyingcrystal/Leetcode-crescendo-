#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int uniquePaths(int m, int n) {
        vector<int> n_column(n + 1, 0);
        vector<vector<int>> w(m + 1, n_column);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                w[i][j] = w[i - 1][j] + w[i][j - 1];
                
            }
        }
    }

};

int main() {
    Solution* ss = new Solution();
    int result = ss->uniquePaths(3, 7);
    cout << result << endl;
    return 0;
}


        