#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Solution() {

    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<int, Node*> copied;
        queue<Node*> oldNodes;
        oldNodes.push(node);
        copied[node->val] = new Node(node->val);
        while(!oldNodes.empty()) {
            Node* oldNode = oldNodes.front();
            oldNodes.pop();
            for(auto& n : oldNode->neighbors) {
                if(copied.find(n->val) == copied.end()) {
                    copied[n->val] = new Node(n->val);
                    oldNodes.push(n);
                }
                copied[oldNode->val]->neighbors.push_back(copied[n->val]);
            }
        }
        return copied[node->val];
    }


    // Node* cloneGraph(Node* node) {
    //     if (node == NULL) return NULL;
    //     unordered_map<int, Node*> discovered;
    //     queue<Node*> oldNodes;
    //     oldNodes.push(node);
    //     discovered[node->val] = new Node(node->val);
    //     while (oldNodes.size() > 0) {
    //         Node* oldNode = oldNodes.front();
    //         oldNodes.pop();
    //         for (auto& n : oldNode->neighbors) {
    //             if (discovered.find(n->val) == discovered.end()) {
    //                 discovered[n->val] = new Node(n->val);
    //                 oldNodes.push(n);
    //             }
    //             discovered[oldNode->val]->neighbors.push_back(discovered[n->val]);
    //         }
    //     }
    //     return discovered[node->val];  
    // }
}

int main() {
    return 0;
}