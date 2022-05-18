#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//这道题每次思维都卡在了，最大值不一定出现在经过当前node，那这样就无法连接下一个node
//解决办法：每次dfs return的都是左+当前节点或者右+当前节点（取两者大值和当前节点拼）或者仅有当前的节点！！
//用一个变量记录下所有情况的最大值即
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int leftMax = dfs(root -> left, ans);
        int rightMax = dfs(root -> right, ans);
        ans = max(ans, max(root -> val, max(root -> val + leftMax, max(root -> val
         + leftMax + rightMax, root -> val + rightMax))));
         //bug: 包含节点在内的路径也有可能只有节点本身（左右最大值都为负数的情况）
        return max(root->val, root -> val + max(leftMax, rightMax));
    }


};