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
//Solution1: recursive
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
//Solution2: iterative
//Since the dfs is actually based on calling recursive stack, we can use stack to implement it iteratively
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* curr = root;

        while (!stk.empty()) {
            while (curr != NULL) {
                if (curr->left != NULL) stk.push(curr->left);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            if (curr->right != NULL) stk.push(curr->right);
            //KEY: no matter curr is null or not, should leave it processed before the next middle node(root) be processed
            curr = curr->right;
        }
        return ans;
    }
};