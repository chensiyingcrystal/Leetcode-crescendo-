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
//problem: understanding of binary balanced tree
//code: great
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root).first;
    }
    
    pair<bool, int> helper(TreeNode* node) {
        if (node == NULL) return {true, 0};
        pair<bool, int> left_res = helper(node->left);
        pair<bool, int> right_res = helper(node->right);
        pair<bool, int> ans;
        ans.first = left_res.first && right_res.first && abs(left_res.second - right_res.second) <= 1;
        ans.second = max(left_res.second, right_res.second) + 1;
        return ans;
    }
//advanced method
//use one variable to represent two information
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        //use -1 to represent unbalanced tree while the height of the root, if
        //it is a balanced tree, is also returned
        return helper(root) != -1;
    }

    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int left = helper(root->left), right = helper(root->right);
        //determine if it's a balanced tree in advance of return; save time
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};