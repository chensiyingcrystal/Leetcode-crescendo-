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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return min(minDepth(root -> left), minDepth(root -> right)) + 1;     
    }
//bfs
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                //!!!!!!always remember to pop!
                q.pop();

                if (node -> left == nullptr && node -> right == nullptr) {
                    return ++level;
                }

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            level++;
        } 
        return level;
    }
};
