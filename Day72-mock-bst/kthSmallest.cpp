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

int findKthNode(TreeNode* root, int k) {
    int ans = -1, count = 0;
    bool found = false;
    dfs(root, k, ans, count, found);
    return found ? ans : -1;
    
}

void dfs(TreeNode*& root, int& k, int& ans, int& count, bool& found) {
    if (root == NULL || found) return;
    
    dfs(root->left, k, ans, count, found);
    count++;
    if (count == k) {
        ans = root->val;
        found = true;
        return;
    }
    dfs(root->right, k, ans, count, found);
}

//find kth largest element in the BST tree: right subtree -> node itself --> left subtree



int main() {
     

}