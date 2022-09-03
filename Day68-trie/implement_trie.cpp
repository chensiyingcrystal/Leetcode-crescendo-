#include <string>

using namespace std;

template<typename V>
class TrieMap {
private:
    int size;
    Trie* trie;

    class Trie {
        bool isEnd;
        V val;
        Trie* children[256];

        Trie() {
            isEnd = false;
            val = NULL;
            for (int i = 0; i < 256; i++) {
                children[i] = NULL;
            }
        }
    };

    Trie* findTrieNode(Trie* trie, string& word, int start) {
        Trie* curr = trie;
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
        trie = new Trie();
    }

    void add(string key, V val) {

    }

    void remove(string key) {

    }

    V getValue(string key) {
        Trie* curr = findTrieNode(trie, key, 0);
        if (curr == NULL) return NULL;
        return curr->val;
    }

    bool findKey(string key) {
        return getValue(key);
    }

    string findLongestPrefix(string query) {
        Trie* curr = trie;
        int maxLen = 0;
        for (int i = 0; i < query.length(); i++) {
            char c = query[i];
            if (curr->children[c] == NULL) {
                return query.substr(0, maxLen);
            }
            curr = curr->children[c];
        }

    }

    vector<string> findAllPrefixKey(string prefix) {

    }

    bool findPrefixKey(string prefix) {

    }

    vector<string> findAllPatternKey(string pattern) {

    }

    bool findPatternKey(string pattern) {

    }

};