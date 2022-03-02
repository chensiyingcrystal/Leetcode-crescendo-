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
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};

    void insert(string& s, TrieNode* head) {
        TrieNode* curr = head;
        for (int i = 0; i < s.length(); i++) {
            int id = s[i] - 97;
            if (curr -> ch[id] == nullptr) {
                curr -> ch[id] = new TrieNode();
            }
            curr = curr -> ch[id];
        }
        curr -> endMark = true;
        //此题目的是返回string，所以很巧妙地可以在这里返回
        curr -> word = s;
    }
//搞清楚传进来的argument和当前board[i][j]的关系，非常容易出错
    void searchWords(vector<vector<char> >& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*') return;
        char tmp = board[i][j];
        if (node -> ch[tmp - 97] == nullptr) return;

        if (node -> ch[tmp - 97] -> endMark) {
            result.push_back(node -> ch[tmp - 97] -> word);
            //避免重复访问，添加入数组
            node -> ch[tmp - 97] -> endMark = false;
        }

        board[i][j] = '*';
        for (int x = 0; x < 4; x++) {
            searchWords(board, i + row[x], j + col[x], node -> ch[tmp - 97], result);
        }
        board[i][j] = tmp;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode* head = new TrieNode();
        for (string& word : words) {
            insert(word, head);
        }

        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int id = board[i][j] - 97;
                searchWords(board, i, j, head, result);
            }
        }

        return result;
    }
};


//Solution2的dfs函数另一种写法: Trie backtracking
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
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};

    void insert(string& s, TrieNode* head) {
        TrieNode* curr = head;
        for (int i = 0; i < s.length(); i++) {
            int id = s[i] - 97;
            if (curr -> ch[id] == nullptr) {
                curr -> ch[id] = new TrieNode();
            }
            curr = curr -> ch[id];
        }
        curr -> endMark = true;
        //此题目的是返回string，所以很巧妙地可以在这里返回
        curr -> word = s;
    }
//将要检查的和邻居放在同层，这样写就一定要注意提前检查索引和访问！！否则很容易出错！！
    void searchWords(vector<vector<char> >& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (node -> endMark) {
            result.push_back(node -> word);
            node -> endMark = false;
        }
        
        char tmp = board[i][j];
        board[i][j] = '*';
        for (int x = 0; x < 4; x++) {
            //这里就要提前对所有条件进行判断, 在使用下一个index前
            if (i + row[x] >= 0 && i + row[x] < board.size() && j + col[x] >= 0 && j + col[x] < board[0].size() 
                && board[i + row[x]][j + col[x]] != '*' && node -> ch[board[i + row[x]][j + col[x]] - 97] != nullptr) {
                searchWords(board, i + row[x], j + col[x], node -> ch[board[i + row[x]][j + col[x]] - 97], result);
            }
        }
        board[i][j] = tmp;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode* head = new TrieNode();
        for (string& word : words) {
            insert(word, head);
        }

        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int id = board[i][j] - 97;
                //dfs函数改动后这里也要及时修改
                if (head -> ch[id] != nullptr) {
                    searchWords(board, i, j, head -> ch[id], result);
                }
            }
        }

        return result;
    }
};