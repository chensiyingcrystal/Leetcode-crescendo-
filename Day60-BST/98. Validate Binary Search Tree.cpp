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
//Solution2: by xiaoxiong
//use information from left tree and right tree
//key: for the base case, max use INT_MIN - 1, min use INT_MAX - 1 since we wish the single node to be a bst
//key2: when return must consider different cases
//Pitfalls: complicate and space complexity is not friendly
    bool isValidBST(TreeNode* root) {
        return helper(root)[0];
    }
    
    vector<long> helper(TreeNode* root) {
        if (root == NULL) {
            return {1, (long)INT_MAX + 1, (long)INT_MIN - 1};
        }
        vector<long>left = helper(root->left);
        if (left[0] != 1 || left[2] >= root->val) return {0, -1, -1};
        vector<long>right = helper(root->right);
        if (right[0] != 1 || right[1] <= root->val) return {0, -1, -1};
        
        if (root->left == NULL && root->right == NULL) return {1, root->val, root->val};
        if (root->left == NULL) return {1, root->val, right[2]};
        if (root->right == NULL) return {1, left[1], root->val};
        return {1, left[1], right[2]};
    }
//Solution1: by me; use one variable's reference
//key: use pre as reference!!! Since we wish the modification left tree makes reflect back to the root
    bool isValidBST(TreeNode* root) {
        long pre = (long)INT_MIN - 1;
        return dfs(root, pre);
    }
    
    bool dfs(TreeNode* root, long& pre) {
        if (root == NULL) return true;
        if (dfs(root->left, pre) == false) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        if (dfs(root->right, pre) == false) return false;
        return true;
    }
};