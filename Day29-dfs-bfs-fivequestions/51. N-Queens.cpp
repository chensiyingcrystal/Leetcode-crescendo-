#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//trick:使用数组记录出现过Q的位置，利用index特点
//time： o(N!)
    vector<vector<string> > solveNQueens(int n) {
        //record result
        vector<vector<string> > ans;
        string s (n, '.');
        vector<string> temp(n, s);
        //record visited
        vector<int> column(n);
        unordered_map<int, int> diag1;
        vector<int> diag2(2 * n);
        backtrack(n, 0, 0, ans, temp, column, diag1, diag2);
        return ans;
    }

    void backtrack(int n, int i, int j, vector<vector<string> >& ans, vector<string>& temp, 
    vector<int>& column, unordered_map<int, int>& diag1, vector<int>& diag2) {
        if (i == n) {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (column[j] == 1 || diag1[i - j] == 1 || diag2[i + j] == 1) continue;
            temp[i][j] = 'Q';
            column[j] = 1;
            diag1[i - j] = 1;
            diag2[i + j] = 1;
            //i作为深度每次递增，因此backtrack内部只需要一次循环
            backtrack(n, i + 1, j, ans, temp, column, diag1, diag2);
            temp[i][j] = '.';
            column[j] = 0;
            diag1[i - j] = 0;
            diag2[i + j] = 0;
        }
    }
};
