#include <string>

using namespace std;

template<typename V>
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

class TrieMap {
public:
    void add(string key, V val) {

    }
};