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
//bfs：推荐；层序遍历，遇到叶子结点提前退出，注意退出时返回当前层的level
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                //！！！always remember to pop!
                q.pop();

                if (node -> left == nullptr && node -> right == nullptr) {
                    //当前层遍历还未结束，此时的level为上一层的
                    //如果探测到叶子结点，则提前结束本层，返回本层最新的level
                    return ++level;
                }

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            level++;
        }
        return level;
    }
//dfs: 这道题推荐采用bfs，因为dfs条件太多了，容易出错
//bug：并非直接返回左右子树的最小值+1，因为当有一边为空时，只考虑另一边
//这道题的recursion关键在于想清楚base case的各类情形是什么，排除这些情形后就自然放心地得到了递归条件
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return dfs(root, 1);
    }

    int dfs(TreeNode* node, int level) {
        if (node -> left == nullptr && node -> right == nullptr) return level;
        if (node -> left == nullptr) return dfs(node -> right, level + 1);
        if (node -> right == nullptr) return dfs(node -> left, level + 1);
        return min(dfs(node -> left, level + 1), dfs(node -> right, level + 1));
    }
//another way: recursively call the function itself
//remember to add two base cases and add if clause ahead of updating mindepth
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;

        int mindepth = INT_MAX;
        if (root -> left != nullptr) {
            mindepth = min(mindepth, minDepth(root -> left) + 1);
        }
        if (root -> right != nullptr) {
            mindepth = min(mindepth, minDepth(root -> right) + 1);
        }
        return mindepth;
    }
//小熊推荐的另一种写法
    int minDepth(TreeNode* root) {
        
    }
};
