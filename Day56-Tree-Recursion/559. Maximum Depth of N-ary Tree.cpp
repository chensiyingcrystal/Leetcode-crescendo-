#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                Node* temp = q.front();
                q.pop();
                for (Node* node : temp->children) {
                    if (node != NULL) q.push(node);
                }
            }
            level++;
        }

        return level;
    }

    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int max_depth = 0;
        for (Node* node : root->children) {
            max_depth = max(max_depth, maxDepth(node));
        }
        return max_depth + 1;
    }
};

