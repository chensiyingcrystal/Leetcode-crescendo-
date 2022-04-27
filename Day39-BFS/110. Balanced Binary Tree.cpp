#include <vector>
#include <unordered_map>
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
//这道题最初写不出来是因为没有理解题意，不能很好地将题目拆分成子问题
//这道题的特点：下层的node的结果会从两方面影响到上层的：
             //第一，左右子树只要有任一子树不符合，母树即可不符合
             //第二，左右子树之间需要满足条件
//自己写的缺点：每次判断完左右子树的平衡之后，还需要重新向下递归计算一遍height
//有没有办法能够一次遍历即可既判断平衡又计算了height呢
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isBalanced(root -> left)) return false;
        if (!isBalanced(root -> right)) return false;
        return abs(treeLevel(root -> left) - treeLevel(root -> right)) <= 1;
    }

    int treeLevel(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(treeLevel(node -> left), treeLevel(node -> right)) + 1;
    }
//one-way: use global variable or reference variable
//小熊推荐的写法: 因为一次遍历需要两个信息，因此我们可以同时返回两个信息
//与dfs tree traversal的题类似，想好base case和该节点的结果是怎么由
//左右子树的dfs结果得来之后就leap of faith！！不要过度思考
//但是注意，每次为了放心不错漏，需要提前思考一下左右子树任一为空的递归方程是不是
//会有所不同，类似题111minimum tree！这样就能更放心地写递归
//此题就是先序遍历+剪枝
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        pair<int, bool> ans = dfs(root);
        return ans.second;
    }

    pair<int, bool> dfs(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, true);
        }
        pair<int, bool> left = dfs(root -> left);
        //add some triming operations 
        if (!left.second) return make_pair(0, false);
        pair<int, bool> right = dfs(root -> right);
        if (!right.second) return make_pair(0, false);
        pair<int, bool> self;
        //两个信息分别是怎样由子节点的结果得到的
        self.first = max(left.first, right.first) + 1;
        //这里如果没有前面的剪枝，应该是3个and
        self.second = abs(right.first - left.first) <= 1;
        return self;
    }

    





};
