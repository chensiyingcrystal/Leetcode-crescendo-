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
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = height(root -> left);


    }

    int height(TreeNode* node) {
        
    }

    





};
