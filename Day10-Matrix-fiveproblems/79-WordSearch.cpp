#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
   Solution() {


   }
// optimized edition: pass dfs depth as argument
    static constexpr int row_arr[] = {-1, 1, 0, 0};
    static constexpr int col_arr[] = {0, 0, -1, 1};

    bool backtrack(vector<vector<char> >& board, int r, int c, string& word, int index) {
        int row = board.size();
        int col = board[0].size();
        // bottom case
        if (index > word.length() - 1) return true;
        // check to see if current cell is valid
        if (r < 0 || r > row - 1 || c < 0 || c > col - 1) return false;
        // including checking if visited       
        if (board[r][c] != word[index]) return false;
        // start dfs
            // mark current cell as visited
            // loop through each four direction
        board[r][c] = '1';
        for(int i = 0; i < 4; i++) {
            if (backtrack(board, r + row_arr[i], c + col_arr[i], word, index + 1)) return true;
        }
        // 
        board[r][c] = word[index];
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int row = board.size();
        int col = board[0].size();
        // loop through each cell and implement backtrack function
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (backtrack(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
// argument: new string; disadvantage: space complexity increase(substr allocate new space)
    // static constexpr int row_arr[] = {-1, 1, 0, 0};
    // static constexpr int col_arr[] = {0, 0, -1, 1};

    // bool backtrack(vector<vector<char> >& board, int r, int c, string suffix) {
    //     int row = board.size();
    //     int col = board[0].size();
    //     // bottom case
    //     if (suffix.empty()) return true;
    //     // check to see if current cell is valid
    //     if (r < 0 || r > row - 1 || c < 0 || c > col - 1) return false;
    //     // including checking if visited       
    //     if (board[r][c] != suffix[0]) return false;
    //     // start dfs
    //         // mark current cell as visited
    //         // loop through each four direction
    //     board[r][c] = '1';
    //     string new_suffix = suffix.substr(1, suffix.length() - 1);
    //     for(int i = 0; i < 4; i++) {
    //         if (backtrack(board, r + row_arr[i], c + col_arr[i], new_suffix)) return true;
    //     }
    //     // 
    //     board[r][c] = suffix[0];
    //     return false;
    // }

    // bool exist(vector<vector<char> >& board, string word) {
    //     int row = board.size();
    //     int col = board[0].size();
    //     // loop through each cell and implement backtrack function
    //     for(int i = 0; i < row; i++) {
    //         for(int j = 0; j < col; j++) {
    //             if (backtrack(board, i, j, word)) return true;
    //         }
    //     }
    //     return false;
    // }
};


int main() {
    return 0;
}