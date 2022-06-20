#include <unordered_map>
#include <queue>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>

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

    void recoverTree(TreeNode* root) {
        inorderLeftToRight(root);
        inorderRightToLeft(root);
        return; 
    }

    TreeNode* inorderLeftToRight(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return root;
        }
        TreeNode* prev = inorderLeftToRight(root->left);
        if (prev->val > root->val) {
            swap(prev->val, root->val);
        }
        return root->right? inorderLeftToRight(root->right) : root;
    }

    TreeNode* inorderRightToLeft(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            return root;
        }

        TreeNode* next = inorderRightToLeft(root->right);
        if (root->val > next->val) {
            swap(root->val, next->val);
        }
        return root->left? inorderRightToLeft(root->left) : root;
    }


};