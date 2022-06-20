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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        dfs(curr, val);
        return root;
    }

    void dfs(TreeNode* curr, int val) {
        if (curr == NULL) {
            curr = new TreeNode(val);
            return;
        }
        if (curr->val < val) {
            dfs(curr->right, val);
            return;
        }
        dfs(curr->left, val);
    }
        
};