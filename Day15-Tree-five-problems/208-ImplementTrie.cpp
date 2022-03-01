#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

class Node {
    public:
    bool endMark;
    Node* ch[26];

    Node() {
        endMark = false;
        for (int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }

};