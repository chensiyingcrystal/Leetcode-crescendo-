#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
//bfs:数level
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp -> left) q.push(tmp -> left);
                if (tmp -> right) q.push(tmp -> right);
            }
            level++;
        }
        return level;
    }
};
