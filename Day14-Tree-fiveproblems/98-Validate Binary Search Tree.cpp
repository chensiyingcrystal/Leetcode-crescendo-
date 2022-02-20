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

bool isValidBST(TreeNode* root, long& min_v, long& max_v) {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            min_v = root->val;
            max_v = root->val;
            return true;
        }
        
        long min_l_v = (long)INT_MAX+1;
        long max_l_v = (long)INT_MIN-1;
        long min_r_v = (long)INT_MAX+1;
        long max_r_v = (long)INT_MIN-1;
        if (root->left != nullptr && !isValidBST(root->left, min_l_v, max_l_v)) {
            return false;
        }
        if (root->right != nullptr && !isValidBST(root->right, min_r_v, max_r_v)) {
            return false;
        }
        if (max_l_v >= root->val) {
            return false;
        }
        if (root->val >= min_r_v) {
            return false;
        }    
        min_v = min(min_l_v, (long) root->val);
        max_v = max(max_r_v, (long) root->val);
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long min_v, max_v;
        return isValidBST(root, min_v, max_v);
    }

};