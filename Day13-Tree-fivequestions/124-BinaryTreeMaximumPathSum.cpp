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
//add another value besides the answer
//for every node, the max value is ans = max(ans, x + max(x.left, 0) + max(x.right, 0))
//This expression can handle every case, including only left or right, because it is updated inside the function
//The other value is M(x) = x + max(max(left, 0), max(right, 0))
//This value is set as their maximum value to pass on to its upper structure
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
        //add &ans to this function to make sure that ans is updated on every node's case
        //including the case in which the maximum value is from the single, isolated node
        ans = max(ans, node -> val + maxLeft + maxRight);
        return node -> val + max(maxLeft, maxRight);
    }
};