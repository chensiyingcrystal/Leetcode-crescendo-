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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int count = 0;
        long long nodeSum = 0;
        dfs(root, nodeSum, targetSum, count);
        if (root -> left != nullptr) count += pathSum(root -> left, targetSum);
        if (root -> right != nullptr) count += pathSum(root -> right, targetSum);
        return count;
    }

    void dfs(TreeNode* root, long long& nodeSum, int targetSum, int& count) {
        nodeSum += (long long)root -> val;
        if (nodeSum == targetSum) count++;
        if (root -> left != nullptr) {
            dfs(root -> left, nodeSum, targetSum, count);
            nodeSum -= (long long)(root -> left) -> val;
        }
        if (root -> right != nullptr) {
            dfs(root -> right, nodeSum, targetSum, count);
            nodeSum -= (long long)(root -> right) -> val;
        }
    }
//another way, directly subtract val from targetSum, do not need nodeSum
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int count = 0;
        dfs(root, (long long)targetSum, count);
        count += pathSum(root -> left, targetSum);
        count += pathSum(root -> right, targetSum);
        return count;
    }

    void dfs(TreeNode* root, long long targetSum, int& count) {
        if (root -> val == targetSum) count++;
        if (root -> left != nullptr) dfs(root -> left, (long long)targetSum - root -> val, count);
        if (root -> right != nullptr) dfs(root -> right, (long long)targetSum - root -> val, count);
    }
};