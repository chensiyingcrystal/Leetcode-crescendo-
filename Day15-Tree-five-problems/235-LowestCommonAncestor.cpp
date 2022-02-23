#include <iostream>
#include <vector>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//针对BST怎么写呢？:根据bst的属性将问题break成子问题分析
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (p -> val < root -> val && q -> val < root -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if (p -> val > root -> val && q -> val > root -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }

//针对所有类型的树的写法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ans_p, ans_q;
        int flag_p = 0, flag_q = 0;
        findAncestor(root, p, ans_p, flag_p);
        findAncestor(root, q, ans_q, flag_q);
        for (int i = 0; i < ans_p.size(); i++) {
            for (int j = 0; j < ans_q.size(); j++) {
                if (ans_p[i] -> val == ans_q[j] -> val) {
                    return ans_p[i];
                } 
            }
        }
        return NULL;
    }

    void findAncestor(TreeNode*& root, TreeNode*& node, vector<TreeNode*>& ans, int& flag) {
        if (root == NULL) return;

        if (root -> val == node -> val) {
            flag = 1;
            ans.push_back(root);
            return;
        }
        findAncestor(root -> left, node, ans, flag);
        if (flag == 1) {
            ans.push_back(root);
            return;
        }
        findAncestor(root -> right, node, ans, flag);
        if (flag == 1) {
            ans.push_back(root);
            return;
        }
    }
};