#include <unordered_map>
#include <unordered_set>
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
//Solution1: intuitive way
    bool hasPathSumII(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return dfs(root, targetSum)
         || hasPathSumII(root->left, targetSum)
          || hasPathSumII(root->right, targetSum);
    }

    bool dfs(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (root->val == targetSum) return true;
        return dfs(root->left, targetSum - root->val) || dfs(root->right, targetSum - root->val);
    }
//Solution2: intuition comes from pathSumIII
    bool hasPathSumII(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        return dfs(root, targetSum, 0, prefix_sum);
    }

    bool dfs(TreeNode* root, int targetSum, int nodeSum, unordered_map<int, int>& prefix_sum) {
        if (root == NULL) return false;
        nodeSum += root->val;
        if (prefix_sum.find(nodeSum - targetSum) != prefix_sum.end() && prefix_sum[nodeSum - targetSum] != 0) {
            return true;
        }

        prefix_sum[nodeSum]++;
        dfs(root->left, targetSum, nodeSum, prefix_sum);
        dfs(root->right, targetSum, nodeSum, prefix_sum);
        prefix_sum[nodeSum]--;
    }
};