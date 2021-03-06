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
        //可以先在主函数中排除root为null的特殊情况
        //如果都放一个函数写，那么可能出现最初root就是空或者是base case是空的情况
        //会比较confuse，所以可以分开写
        //但是如果一旦放另外一个函数写，那么后面的case加入子树时一定记得排除为空的情况
        if (root == nullptr) return 0;
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        //这里root肯定不会为null，那么base case考虑叶子的情况
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        //注意⚠️写递归方程前考虑下左或右为空会不会对结果有影响
        //对于本题，理解题意后会发现，左右子树任一为空和两边为空时候的递归方程是不一样的
        //重要思维：思考root这步是如何由root下面的左右两个部分得到的结果！！！
        //因为此时base case中最低只考虑叶子情况，因此加入子树时必须对空的情况进行拦截！
        if (root -> left == nullptr) {
            return dfs(root -> right) + 1;
        }
        else if (root -> right == nullptr) {
            return dfs(root -> left) + 1;
        }
        else {
            return min(dfs(root -> left), dfs(root -> right)) + 1;
        }
    }
};
