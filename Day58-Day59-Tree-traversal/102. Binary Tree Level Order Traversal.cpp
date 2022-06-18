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

    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            vector<int> temp;
            while (k--) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;    
    }

};