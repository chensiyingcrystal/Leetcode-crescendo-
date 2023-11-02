#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

struct Trie {
    vector<Trie*> children;
    bool isEnd;
    Trie(): children(26), isEnd(false) {}
};

Trie* root;

void backtrack(Trie* root, string& temp) {
    if (root == nullptr) { return; }
    if (root->isEnd) {
        cout << temp << endl;
    }

    for (int i = 0; i < 26; i++) {
        char c = i + 'a';
        temp += c;
        backtrack(root->children[i], temp);
        temp.pop_back();
    }
}

void printTrie() {
    string temp = "";
    backtrack(root, temp);
}

void buildTrie(vector<string>& forbidden) {
    root = new Trie();
    for (auto& word : forbidden) {
        Trie* curr = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == nullptr) { curr->children[idx] = new Trie(); }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
}

//find the shortest postfix in the range[l, r], return the index of the shortest postfix's start
int findShortestPostFix(string& word, int& l, int& r) {
    Trie* curr = root;
    int i = r;
    while (i >= l) {
        int idx = word[i] - 'a';
        if (curr->children[idx] == nullptr) {
            return -1;
        }
        if (curr->children[idx]->isEnd) break;
        curr = curr->children[idx];
        i--;
    }
    return i;
}

int longestValidSubstring(string word, vector<string>& forbidden) {
    buildTrie(forbidden);
    //printTrie();

    //search postfix
    int left = 0, right = 0;
    int maxLen = INT_MIN;
    while (right < word.length()) {
        int prev = findShortestPostFix(word, left, right);
        left = prev == -1 ? left : prev + 1;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen == INT_MIN ? 0 : maxLen;



    return 0;

}





int main() {
    string word = "cbaaaabc";
    vector<string> forbidden = {"aaa","cb"};
    int ans = longestValidSubstring(word, forbidden);
    



    return 0;


}