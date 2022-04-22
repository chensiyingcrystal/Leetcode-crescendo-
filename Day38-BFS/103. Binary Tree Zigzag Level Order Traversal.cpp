#include <vector>
#include <unordered_set>
#include <queue>

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* node, int level, vector<vector<int> >& ans) {
        if (level == ans.size()) {
            vector<int> tmp;
            ans.push_back(tmp);
        }

        ans[level].push_back(node -> val);
        if ((level + 1) % 2 != 0) {
            if (node -> right != nullptr) dfs(node -> right, level + 1, ans);
            if (node -> left != nullptr) dfs(node -> left, level + 1, ans);
        }
        else {
            if (node -> left != nullptr) dfs(node -> left, level + 1, ans);
            if (node -> right != nullptr) dfs(node -> right, level + 1, ans); 
        }
    }
//bfs
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int k = q.size();
            vector<int> tmp;
            while(k--) {
                TreeNode* node = q.front();
                q.pop();

                tmp.push_back(node -> val);
                if ((level + 1) % 2 != 0) {
                    if (node -> right != nullptr) q.push(node -> right);
                }

            }
        }
    }
};
