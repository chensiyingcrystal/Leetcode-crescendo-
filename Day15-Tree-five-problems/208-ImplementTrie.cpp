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
    Node* head;

    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* curr = head;
        for (char& c : word) {
            int id = c - 97;
            if (curr -> ch[id] == nullptr) {
                curr -> ch[id] = new Node();
            }
            curr = curr -> ch[id];
        }
        curr -> endMark = true;
    }
    
    bool search(string word) {
        Node* curr = head;
        for (char& c : word) {
            int id = c - 97;
            if (curr -> ch[id] == nullptr) {
                return false;
            }
            curr = curr -> ch[id];
        }
        return curr -> endMark;
    }
    
    bool startsWith(string prefix) {
        Node* curr = head;
        for (char& c : prefix) {
            int id = c - 97;
            if (curr -> ch[id] == nullptr) {
                return false;
            }
            curr = curr -> ch[id];
        }
        return true;
    }
};