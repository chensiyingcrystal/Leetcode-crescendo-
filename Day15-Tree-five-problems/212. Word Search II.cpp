#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

//方法一：普通的backtracking会超时
class Solution {
public:
    int i_n[4] = {0, 0, 1, -1};
    int j_n[4] = {1, -1, 0, 0};

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> result;
        for (string& word : words) {
            char c = word[0];
            bool flag = false;
            for (int i = 0; i < board.size(); i++) {
                if (flag) break;
                for (int j = 0; j < board[0].size(); j++) {
                    if (flag) break;
                    if (board[i][j] != c) continue;
                    if (findCharacters(board, word, 0, i, j)) {
                        result.push_back(word);
                        //如果仅仅设置一个break是不够的，外面有两层循环！！设置一个flag就好！！
                        flag = true;
                    } 
                }
            }
        }
        return result;
    }

    bool findCharacters(vector<vector<char> >& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        char c = word[k];
        if (board[i][j] != c) return false;
        if (k == word.length() - 1) return true;

        //bug: 用ascii值标记时，在进行对比时，还是会转化为字符，所以这里不能用！！
        char tmp = board[i][j];
        board[i][j] = '*';
        bool ans = findCharacters(board, word, k + 1, i + i_n[0], j + j_n[0]) 
                    || findCharacters(board, word, k + 1, i + i_n[1], j + j_n[1]) 
                    || findCharacters(board, word, k + 1, i + i_n[2], j + j_n[2]) 
                    || findCharacters(board, word, k + 1, i + i_n[3], j + j_n[3]);
        board[i][j] = tmp;
        return ans;
    }
};

//Solution2: Trie backtracking
class TrieNode {
public:
    bool endMark;
    string word;
    TrieNode* ch[26];

    TrieNode() {
        endMark = false;
        word = "";
        for (int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
};

class Solution {
public:
    void insert(string s, TrieNode* head) {
        TrieNode* curr = head;
        for (int i = 0; i < s.length(); i++) {
            int id = s[i] - 97;
            if (curr -> ch[id] == nullptr) {
                curr -> ch[id] = new TrieNode();
            }
            curr = curr -> ch[id];
        }
        curr -> endMark = true;
        curr -> word = s;
    }

    void searchWords(vector<vector<int> >& board, int i, int j, TrieNode* node, vector<string> result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board.size() || board[i][j] == '*') return;
        if (node == nullptr) return;

        if (node -> endMark) {
            result.push_back(node -> word);
            node -> endMark = false;
        }


    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode* head = new TrieNode();
        for (string& word : words) {
            insert(word, head);
        }

        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                searchWords();
            }
        }

        return result;
    }

};
