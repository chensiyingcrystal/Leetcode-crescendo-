#include <vector>
#include <unordered_set>
#include <queue>

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
//method1: bfs(iteratively)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root -> left == nullptr && root -> right == nullptr) return true;
        if (root -> left == nullptr || root -> right == nullptr) return false;
        
        queue<TreeNode*> qleft;
        queue<TreeNode*> qright;
        qleft.push(root -> left);
        qright.push(root -> right);
        while (!qleft.empty() && !qright.empty()) {
            TreeNode* q1 = qleft.front();
            TreeNode* q2 = qright.front();
            qleft.pop();
            qright.pop();

            if (q1 -> val != q2 -> val) return false;
            if (q1 -> left == nullptr && q2 -> right != nullptr) return false;
            if (q1 -> left != nullptr && q2 -> right == nullptr) return false;
            if (q1 -> left != nullptr && q2 -> right != nullptr) {
                qleft.push(q1 -> left);
                qright.push(q2 -> right);
            }

            if (q1 -> right == nullptr && q2 -> left != nullptr) return false;
            if (q1 -> right != nullptr && q2 -> left == nullptr) return false;
            if (q1 -> right != nullptr && q2 -> left != nullptr) {
                qleft.push(q1 -> right);
                qright.push(q2 -> left);
            }
        }
        return true;
    }
//method2: dfs(recursively)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root -> left, root -> right);
    }

    bool dfs(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;
        if (node1 -> val != node2 -> val) return false;

        return dfs(node1 -> left, node2 -> right) && dfs(node1 -> right, node2 -> left);
    }
};
