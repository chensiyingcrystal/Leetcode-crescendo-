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

class WordDictionary {
public:
    Node* head;

    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        
    }
    
    bool search(string word) {
        
    }
};
