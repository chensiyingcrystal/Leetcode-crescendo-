#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

//行和列容易混乱；返回值必须是先n - 1再m-1；for循环也是
    int uniquePaths(int m, int n) {
        if(m == 0 && n == 0) return 0;
        //should be optimized
        // vector<int> row(m, 0);
        // vector<vector<int>> w(n, row);
        //optimized
        auto w = vector<vector<int>>(n, vector<int>(m, 0));
        for(int x = 0; x < m; ++x) w[0][x] = 1;
        for(int x = 0; x < n; ++x) w[x][0] = 1;

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                w[i][j] = w[i - 1][j] + w[i][j - 1];
            }
        }
        return w[n - 1][m - 1];
    }
};

int main() {
    Solution* ss = new Solution();
    int result = ss->uniquePaths(3, 7);
    cout << result << endl;
    return 0;
}


        