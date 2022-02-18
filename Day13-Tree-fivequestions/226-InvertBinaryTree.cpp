#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {


    }
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

//time: o(N) 
//space: worst case in the queue there are at most n nodes, where n is the nodes at the base level
//assuming N is the level, the nodes at that level is 2^N
//total nodes is 2^0 + 2^1 + 2^2 + ... + 2^N = 2^(N+1) - 1(2Sn - Sn)
//--> the number of nodes at the base level is about half of the total nodes
//if N is the total nodes, space complexity is o(N/2) = o(N)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* tmp = node -> right;
            node -> right = node -> left;
            node -> left = tmp;
            if (node -> right) q.push(node -> right);
            if (node -> left) q.push(node -> left);
        }
        return root;
    }
};