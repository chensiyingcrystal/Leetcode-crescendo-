#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

class Node {
//bug: must add public here, otherwise not allowed to visit Node()
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
    
    bool search(string word, int k, Node* node) {
        Node* curr = node;
        for (int i = k; i < word.length(); i++) {
            if (word[i] != '.') {
                int id = word[i] - 97;
                if (curr -> ch[id] == nullptr) return false;
                curr = curr -> ch[id];
            }
            else {
                //recursive design: pass index instead of substr as argument; 
                //use level as depth: pass node as argument
                for (int j = 0; j < 26; j++) {
                    if (curr -> ch[j] == nullptr) continue;
                    //bug: not directly return; Any search return true, return true
                    if (search(word, i + 1, curr -> ch[j])) return true;
                }
                //bug: must add this; when for loop above end, nothing returned but false
                return false;
            }
        }
        return curr -> endMark;
    }

    bool search(string word) {
        return search(word, 0, head);
    } 
};
