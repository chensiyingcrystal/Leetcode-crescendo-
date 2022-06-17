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
//easy way to do this: do level traversal and then reverse the result
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
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

        reverse(ans.begin(), ans.end());
        return ans;
    }
//learn how to do level traversal using dfs!!
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int> > ans;
        dfs(root, ans, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(TreeNode* root, vector<vector<int> >& ans, int level) {
        if (root == NULL) return;
        if (level == ans.size()) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(root->val);
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
//write first time
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        stack<TreeNode*> stk;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            ans.push_back(vector<int>(k)); 
            while (k--) {
                TreeNode* temp = q.front();
                q.pop();
                stk.push(temp);
                if (temp->right != NULL) q.push(temp->right);
                if (temp->left != NULL) q.push(temp->left);
            }
        }
        
        int m = ans.size();
        for (int i = m - 1; i >= 0; i--) {
            int n = ans[i].size();
            for (int j = 0; j < n; j++) {
                TreeNode* tmp = stk.top();
                stk.pop();
                ans[i][j] = tmp->val;
            }
        }
        
        vector<vector<int> > new_ans;
        for (int x = m - 1; x >= 0; x--) {
            new_ans.push_back(ans[x]);
        }

        return new_ans;

    }

};