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
//time: traverse the entire tree and each node one, the total run time is O(N)
//space: the worst case, the maximum nodes in the queue is n; O(n)
//正向的遍历：在初始化q之前，将非空的左右子树加入q；
            //对当前的node进行判断处理
            //在满足一定条件后将node的child加入q
            //继续下一轮循环直至q为空
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
//time: o(n)
//space: o(n); in the worst case, the tree is linear and the height is o(n)
//递归的思想：需要建立helper function，进行两个node是否symmetric的判断，这是从root的下一层开始的
            //base case：两个都为空；一个为空，一个不为空；两个数值不相等；都可以直接返回结果
            //递归：由下一个bottom层级的结果决定
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
//bfs自己再敲一遍
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (root -> left == nullptr && root -> right == nullptr) return true;
        if (root -> left == nullptr || root -> right == nullptr) return false;

        queue<TreeNode*> qleft;
        queue<TreeNode*> qright;
        qleft.push(root -> left);
        qright.push(root -> right);
        while(!qleft.empty() && !qright.empty()) {
            TreeNode* tleft = qleft.front();
            qleft.pop();
            TreeNode* tright = qright.front();
            qright.pop();

            if (tleft -> val != tright -> val) return false;
            if (!tleft -> left && tright -> right) return false;
            if (tleft -> left && !tright -> right) return false;
            if (tleft -> left && tright -> right) {
                qleft.push(tleft -> left);
                qright.push(tright -> right);
            }

            if (!tleft -> right && tright -> left) return false;
            if (tleft -> right && !tright -> left) return false;
            if (tleft -> right && tright -> left) {
                qleft.push(tleft -> right);
                qright.push(tright -> left);
            }
        }
        return true;
    }
//dfs自己再敲一遍
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root -> left, root -> right);
    }

    bool dfs(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;
        if (node1 -> val != node2 -> val) return false;
        return dfs(node1 -> left, node2 -> right) && dfs(node1 -> right, node2 -> left);
    }
};
