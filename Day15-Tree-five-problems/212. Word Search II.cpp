#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> result;
        for (string& word : words) {
            char c = word[0];
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] != c) continue;
                    if (word.length() == 1 || findCharacters(board, word, 1, i, j)) {
                        result.push_back(word);
                    } 
                }
            }
        }
        return result;
    }

    bool findCharacters(vector<vector<char> >& board, string& word, int k, int i, int j) {

    }
};