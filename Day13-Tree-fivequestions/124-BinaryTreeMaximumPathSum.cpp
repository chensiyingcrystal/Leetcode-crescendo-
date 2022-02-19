#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        maxCurrsum(root, ans);
        return ans;
    }

    int maxCurrsum(TreeNode* node, int& ans) {
        if (!node) return 0;
        int maxLeft = max(maxCurrsum(node -> left, ans), 0);
        int maxRight = max(maxCurrsum(node -> right, ans), 0);
        ans = max(ans, node -> val + maxLeft + maxRight);
        return node -> val + max(maxLeft, maxRight);
    }
};