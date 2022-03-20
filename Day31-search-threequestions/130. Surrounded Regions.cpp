#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
//理解题意：先捕获所有边界和与之相连的，剩下的直接变成x即可
    void solve(vector<vector<char> >& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') board[i][j] = 'O';
                //bug：r变成o和o变成x是二选一的关系！！！千万不要连着写两个if；或者可以将两个顺序对调
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }

    void dfs(vector<vector<char> >& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (board[i][j] != 'O') return;

        board[i][j] = 'R';
        
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    
};

