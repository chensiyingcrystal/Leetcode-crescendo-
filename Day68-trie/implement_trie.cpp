#include <string>

using namespace std;



template<typename V>
class TrieMap {
private:
    const int R = 256;
    int size;

    class TrieNode {
    public:
        V val;
        TrieNode* children[R];

        TrieNode() {
            val = NULL;
            for (int i = 0; i < R; i++) {
                children[i] = NULL;
            }
        }
    };

    TrieNode* root;

    TrieNode* getNode(TrieNode* node, string& word, int start) {
        TrieNode* curr = node;
        for (int i = start; i < word.length(); i++) {
            char c = word[i];
            if (curr->children[c] == NULL) return NULL;
            curr = curr->children[c];
        }
        return curr;
    }

public:
    TrieMap() {
        size = 0;
        root = new TrieNode();
    }

    void add(string key, V val) {

    }

    void remove(string key) {

    }

    void V get(string key) {

    }

    bool findKey(string key) {

    }

    string findShortestPrefix(string query) {

    }

    string findLongestPrefix(string query) {

    }

    vector<string> findAllPrefixKey(string prefix) {

    }

    bool findPrefixKey(string prefix) {

    }

    vector<string> findAllPatternKey(string pattern) {

    }

    bool findPatternKey(string pattern) {

    }

    int getSize() {
        return size;
    }


};