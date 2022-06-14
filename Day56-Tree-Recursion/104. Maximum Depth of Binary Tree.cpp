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
//recursion: 
//base case: null
//recursive equation
//time: o(n); space: o(n)
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
//bfs: not as intuitive as dfs
//convert this question to bfs problem: how many levels in this tree?
//level traversing
        int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            level++;
        }
        
        return level;
    }
};