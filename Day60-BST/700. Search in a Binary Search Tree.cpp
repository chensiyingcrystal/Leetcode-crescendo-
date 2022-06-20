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
//recursively
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if (root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);    
    }
//iteratively: pointer
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        //Before write ->val must ensure that curr is not null
        while (curr != NULL && curr->val != val) {
            curr = curr->val > val? curr->left : curr->right;
        }
        return curr;
    }
        
};