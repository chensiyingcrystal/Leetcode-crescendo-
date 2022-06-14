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
//bfs
//bug: not level by level traversing the tree
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left == NULL && tmp->right == NULL) {
                    return level;
                }
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            level++;
        }
        return level;
    }
//dfs
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left == NULL) return minDepth(root->right) + 1;
        if (root->right == NULL) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

};