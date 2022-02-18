#include <iostream>
#include <vector>
#include <unordered_map>

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
//简洁的写法
//time o(|V|) space o(1)
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }

//自己第一遍写的
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        //传的是指针，所以这里用箭头
        return max(dfs(node -> left) + 1, dfs(node -> right) + 1);
    }
};