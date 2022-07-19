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
    int totalNQueens(int n) {
        //must initialize a value!!!
        int ans = 0;
        //space++, time--
        unordered_set<int> column;
        unordered_set<int> diag_left;
        unordered_set<int> diag_right;
        backtrack(ans, column, diag_left, diag_right, 0, n);
        return ans;
    }
    
    void backtrack(int& ans, unordered_set<int>& column, unordered_set<int>& diag_left, unordered_set<int>& diag_right, int i, int& n) { 
        //base case: if we find an answer
        if (i == n) {
            ans++;
            return;
        }
        
        //choice selection
        for (int j = 0; j < n; j++) { 
            if (isValid(column, diag_left, diag_right, i, j)) {
                column.insert(j);
                diag_left.insert(j - i);
                diag_right.insert(i + j);
                backtrack(ans, column, diag_left, diag_right, i + 1, n);
                diag_right.erase(i + j);
                diag_left.erase(j - i);
                column.erase(j);
            }
        }
    }
    
    //举例子， 写出来， 加点comment
    //时间复杂度的分析 主动分析
    //矩阵基本（90，180， 270，
    //语速慢，慢，慢
    bool isValid(unordered_set<int>& column, unordered_set<int>& diag_left, unordered_set<int>& diag_right, int i, int j) {
        if (column.count(j)) return false;
        if (diag_left.count(j - i)) return false;
        if (diag_right.count(i + j)) return false;
        return true;
    } 
};