#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        backtrack(board, 0, 0);
    }
    
    bool backtrack(vector<vector<char> >& board, int row, int col) {
        //col go out of the boarder
        if (col == 9) {
            row += 1;
            col = 0;
        }
        
        //end condition
        if (row == 9) {
            return true;
        }
        
        //skip existing number to next empty cell
        if (board[row][col] != '.') {
            return backtrack(board, row, col + 1);
        }
        
        //enter into current cell, do choice, go to next cell, if no solution then rescind choice
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c) == false) continue;
            board[row][col] = c;
            if (backtrack(board, row, col + 1)) {
                return true;
            }
            board[row][col] = '.';
        }
        return false;
    }
    
    bool isValid(vector<vector<char> >& board, int row, int col, char c) {
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == c || board[x][col] == c) return false;
        }
        
        int box_num = (row / 3) * 3 + (col / 3);
        int start_row = (box_num / 3) * 3;
        int start_col = (box_num % 3) * 3;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                if (board[i][j] == c) return false;
            }
        }
        
        return true;
    }

};