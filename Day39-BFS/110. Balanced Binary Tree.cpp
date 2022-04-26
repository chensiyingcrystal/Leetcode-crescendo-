#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isBalanced(root -> left)) return false;
        if (!isBalanced(root -> right)) return false;
        return abs(treeLevel(root -> left) - treeLevel(root -> right)) <= 1;
    }

    int treeLevel(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(treeLevel(node -> left), treeLevel(node -> right)) + 1;
    }

    





};
