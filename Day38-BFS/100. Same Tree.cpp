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
//method1: recursion
//time complexity: the number of nodes visited: o(min(m, n))
//space complexity: the smaller depth of the tree: o(min(logm, logn))
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p -> val != q -> val) return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
//method2: bfs
//create two queues
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        queue<TreeNode*> pq, qq;
        pq.push(p);
        qq.push(q);
        while(!pq.empty() && !qq.empty()) {
            TreeNode* tmp = pq.front();
            TreeNode* tmq = qq.front();
            pq.pop();
            qq.pop();

            if (tmp -> val != tmq -> val) return false;

            if (tmp -> left == nullptr && tmq -> left != nullptr) return false;
            if (tmp -> left != nullptr && tmq -> left == nullptr) return false;
            if (tmp -> left != nullptr && tmq -> left != nullptr) {
                pq.push(tmp -> left);
                qq.push(tmq -> left);
            }

            if (tmp -> right == nullptr && tmq -> right != nullptr) return false;
            if (tmp -> right != nullptr && tmq -> right == nullptr) return false;
            if (tmp -> right != nullptr && tmq -> right != nullptr) {
                pq.push(tmp -> right);
                qq.push(tmq -> right);
            }
        }
        return true;
    }
};
