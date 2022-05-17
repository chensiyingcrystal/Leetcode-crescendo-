#include <vector>
#include <unordered_map>
#include <numeric>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root -> left == nullptr && root -> right == nullptr) return root -> val == targetSum;
        int newtargetSum = targetSum - root -> val;
        return hasPathSum(root -> left, newtargetSum) || hasPathSum(root -> right, newtargetSum);
    }
//another method: not recommended, backtracking
//not asking path sum along each node, but from root to leaf, thus not requiring backtracking
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        int nodeSum = 0;
        return backtracking(root, nodeSum, targetSum);
    }

    bool backtracking(TreeNode* root, int& nodeSum, int targetSum) {
        if (root -> left == nullptr && root ->right == nullptr) {
            nodeSum += root -> val;
            return nodeSum == targetSum;
        }

        nodeSum += root -> val;
        bool ans;
        if (root -> left != nullptr) ans = backtracking(root -> left, nodeSum, targetSum);
        if (ans) return true;
        //bug: point to null pointer; must add != nullptr condition
        if (root -> left != nullptr) nodeSum -= (root -> left) -> val;
        if (root -> right != nullptr) ans = backtracking(root -> right, nodeSum, targetSum);
        if (ans) return true;
        if (root -> right != nullptr) nodeSum -= (root -> right) -> val;
        return false;
    }
};