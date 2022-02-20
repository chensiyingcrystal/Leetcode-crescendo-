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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> in_left, in_right;
        int k;
        for (int i = 0; i < inorder.size(); i++) {
            k = i;
            if (inorder[i] == preorder[0]) break;
            in_left.push_back(inorder[i]);  
        }

        for (int j = k + 1; j < inorder.size(); j++) {
            in_right.push_back(inorder[j]);
        }

        vector<int> pre_left, pre_right;
        for (int i = 1; i < in_left.size(); i++) {
            pre_left.push_back(preorder[i]);
        }

        for (int j = in_left.size() + 1; j < preorder.size(); j++) {
            pre_right.push_back(preorder[j]);
        }

        root -> left = buildTree(pre_left, in_left);
        root -> right = buildTree(pre_right, in_right);

        return root;
    }

};