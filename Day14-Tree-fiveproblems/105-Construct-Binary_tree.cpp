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
//第一遍自己写的
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        
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
        for (int i = 1; i < in_left.size() + 1; i++) {
            pre_left.push_back(preorder[i]);
        }

        for (int j = in_left.size() + 1; j < preorder.size(); j++) {
            pre_right.push_back(preorder[j]);
        }

        root -> left = buildTree(pre_left, in_left);
        root -> right = buildTree(pre_right, in_right);

        return root;
    }

//简洁的方法：遇到类似的从相对位置走确定步长的，传参数
//更省时，上面的方法每次都需要新建动态数组
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps > pe) return NULL;
        
        int i = 0;
        while (inorder[is + i] != preorder[ps]) i++; 

        TreeNode* root = new TreeNode(preorder[ps]);

        root -> left = helper(preorder, ps + 1, ps + i, inorder, is, is + i - 1);
        root -> right = helper(preorder, ps + i + 1, pe, inorder, is + i + 1, ie);

        return root;
    }
};