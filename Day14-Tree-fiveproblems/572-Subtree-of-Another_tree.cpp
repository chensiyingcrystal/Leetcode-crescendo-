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
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

//wrote by myself: bfs + recursive
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot) return false;
        if (root && !subRoot) return true;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();

            bool result = compare(tmp, subRoot);
            if (result) return true;
            else {
                if (tmp -> left != NULL) q.push(tmp -> left);
                if (tmp -> right != NULL) q.push(tmp -> right);
            } 
        }
        return false;
    }

    bool compare(TreeNode*& node, TreeNode*& subRoot) {
        if (node == NULL && subRoot == NULL) return true;
        if (node == NULL && subRoot != NULL) return false;
        if (node != NULL && subRoot == NULL) return false;

        if (node -> val == subRoot -> val) {
            return compare(node -> left, subRoot -> left) && compare(node -> right, subRoot -> right);
        }
        else return false;
    }

//more concise easy solution: recursive
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //the other cases will be checked in the compare function
        //anything that is recursived in this function is the root
        //so must add this base case to prevent root to be null
        //must have base case for a recursive function
        if (root == NULL) return false;

        if (compare(root, subRoot)) return true;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }

    bool compare(TreeNode*& node, TreeNode*& subRoot) {
        //all three can be contracted
        if (node == NULL && subRoot == NULL) return true;
        else if (node == NULL || subRoot == NULL) return false;

        return node -> val == subRoot -> val && compare(node -> left, subRoot -> left) && 
               compare(node -> right, subRoot -> right);
    }
};