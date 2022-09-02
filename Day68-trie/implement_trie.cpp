#include <string>

using namespace std;



template<typename V>
class TrieMap {
private:
    const int R;
    int size;

    class TrieNode {
    public:
        V val;
        TrieNode* children[256];

        TrieNode() {
            val = NULL;
            for (int i = 0; i < 256; i++) {
                children[i] = NULL;
            }
        }
    };

    TrieNode* root;


public:
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