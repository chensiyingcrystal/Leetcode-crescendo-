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

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            return root->val == targetSum;
        }
        return hasPathSum(root->left, targetSum - root->val) 
            || hasPathSum(root->right, targetSum - root->val);
    }
//if not required starting from the root and ending at leaf, how to write the code?

    bool hasPathSumII(TreeNode* root, int targetSum) {


    }
};