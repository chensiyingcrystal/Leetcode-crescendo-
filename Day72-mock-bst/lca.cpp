#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {

    }

    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ancestor = NULL;
    if (p->val > q->val) {
        TreeNode* temp = p;
        p = q;
        q = temp;
    }
    dfs(root, p, q, ancestor);
    return ancestor;

        
}

void dfs(TreeNode*& node, TreeNode*& p, TreeNode*& q, TreeNode*& ancestor) {
    if (node == NULL) return;
    if (ancestor != NULL) return;
    if (node->val == p->val || node->val == q->val) {
        ancestor = node;
        return;
    }

    if (p->val < node->val && q->val > node->val) {
        ancestor = node;
        return;
    }

    if (q->val < node->val) {
        dfs(node->left, p, q, ancestor);
        return;
    }

    if (p->val > node->val) {
        dfs(node->right, p, q, ancestor);
        return;
    }

}



int main() {
     

}