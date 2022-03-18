#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char> >& board, int i, int j, string& word, int x) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[x]) return false;
        if (x == word.length() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '*';
        bool result = backtrack(board, i + 1, j, word, x + 1) || backtrack(board, i - 1, j, word, x + 1)
        || backtrack(board, i, j + 1, word, x + 1) || backtrack(board, i, j - 1, word, x + 1);
        board[i][j] = temp;
        return result;
    }
};
