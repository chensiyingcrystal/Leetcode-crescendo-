#include <unordered_map>
#include <queue>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>

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
        int m = preorder.size();
        int n = inorder.size();
        return helper(preorder, 0, m - 1, inorder, 0, n - 1);
    }

    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return NULL;
        }
        if (pre_start == pre_end) {
            TreeNode* temp = new TreeNode(preorder[pre_start]);
            return temp;
        }
        
        int pivot;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == preorder[pre_start]) {
                pivot = i; 
                break;
            }
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        int left_number = pivot - in_start;

        root->left = helper(preorder, pre_start + 1, pre_start + left_number, inorder, in_start, pivot - 1);
        root->right = helper(preorder, pre_start + left_number + 1, pre_end, inorder, pivot + 1, in_end);
        return root;
    }

};