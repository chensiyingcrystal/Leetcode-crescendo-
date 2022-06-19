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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* node, vector<int>& ans) {
        if (node -> left != nullptr) dfs(node -> left, ans);
        if (node -> right != nullptr) dfs(node -> right, ans);
        ans.push_back(node -> val);
    }
//Solution2: iterative
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> stack1, stack2;
        stack1.push(root);
        
        while (!stack1.empty()) {
            TreeNode* temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
            if (temp->left != NULL) stack1.push(temp->left);
            if (temp->right != NULL) stack1.push(temp->right);
        }

        while (!stack2.empty()) {
            ans.push_back(stack2.top()->val);
            stack2.pop();
        }

        return ans;
    }
};