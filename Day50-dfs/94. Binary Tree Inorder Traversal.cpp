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
//dfs
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;
        dfs(node -> left, ans);
        ans.push_back(node -> val);
        dfs(node -> right, ans);
    }
//alternative way to write dfs function
    void dfs(TreeNode* node, vector<int>& ans) {
        if (node -> left != nullptr) dfs(node -> left, ans);
        ans.push_back(node -> val);
        if (node -> right != nullptr) dfs(node -> right, ans);
    }
};