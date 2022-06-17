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
//use bfs level traversal and always add the first one to the answer
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            ans.push_back((q.front())->val);
            while (k--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->right != NULL) q.push(node->right);
                if (node->left != NULL) q.push(node->left);
            }
        }
        return ans;
    }
//using dfs level traversal and each time we meet the start of a new level just add it to the answer
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) return;
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        dfs(root->right, ans, level + 1);
        dfs(root->left, ans, level + 1);
    }
};