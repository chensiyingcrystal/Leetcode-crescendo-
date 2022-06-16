#include <unordered_map>
#include <queue>
#include <sstream>

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

    int diameterOfBinaryTree(TreeNode* root) {
        int max_length = 0;
        helper(root, max_length);
        return max_length;
    }
    
    int helper(TreeNode* root, int& max_length) {
        if (root == NULL) return -1;
        int left = helper(root->left, max_length);
        int right = helper(root->right, max_length);
        //what we update here is the longest path's length; this path must pass the root
        max_length = max(max_length, left + right + 2);
        //what we return here is the longer path's length; this path only contain left or right subtree
        return max(left, right) + 1;
    }
};