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

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root).first;
    }
    
    pair<bool, int> helper(TreeNode* node) {
        if (node == NULL) return {true, 0};
        pair<bool, int> left_res = helper(node->left);
        pair<bool, int> right_res = helper(node->right);
        pair<bool, int> ans;
        ans.first = left_res.first && right_res.first && abs(left_res.second - right_res.second) <= 1;
        ans.second = max(left_res.second, right_res.second) + 1;
        return ans;
    }
};