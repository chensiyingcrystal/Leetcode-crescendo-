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
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int count = 0;
        long long nodeSum = 0;
        dfs(root, nodeSum, targetSum, count);
        if (root -> left != nullptr) count += pathSum(root -> left, targetSum);
        if (root -> right != nullptr) count += pathSum(root -> right, targetSum);
        return count;
    }

    void dfs(TreeNode* root, long long& nodeSum, int targetSum, int& count) {
        nodeSum += (long long)root -> val;
        if (nodeSum == targetSum) count++;
        if (root -> left != nullptr) {
            dfs(root -> left, nodeSum, targetSum, count);
            nodeSum -= (long long)(root -> left) -> val;
        }
        if (root -> right != nullptr) {
            dfs(root -> right, nodeSum, targetSum, count);
            nodeSum -= (long long)(root -> right) -> val;
        }
    }
//another way, directly subtract val from targetSum, do not need nodeSum
//注意数据量有可能超出int边界！！！
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int count = 0;
        dfs(root, (long long)targetSum, count);
        //外层循环：有限递归左右子树，确定不同起点
        count += pathSum(root -> left, targetSum);
        count += pathSum(root -> right, targetSum);
        return count;
    }

    void dfs(TreeNode* root, long long targetSum, int& count) {
        //由于往下继续深搜，这里不return
        if (root -> val == targetSum) count++;
        if (root -> left != nullptr) dfs(root -> left, (long long)targetSum - root -> val, count);
        if (root -> right != nullptr) dfs(root -> right, (long long)targetSum - root -> val, count);
    }
//小熊写的，时间复杂度o(n)
    void dfs(TreeNode* node, int targetSum, int currentVal, 
        int& count, unordered_map<int>& visited) {
        if (node == nullptr) {
            return;
        }
        currentVal = currentVal + node->val;
        int delta = currentVal - targetSum;
        if (visited.count(delta)) {
            count += visited[delta];
        }
        visited[currentVal]++;
        dfs(node->left, targetSum, currentVal, count, visited);
        dfs(node->right, targetSum, currentVal, count, visited);
        visited[currentVal]--;
    } 

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int> visited;
        int count = 0;
        dfs(root, targetSum, 0, count, visited);
        return count;
    }
//自己写的
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        int count = 0;
        long long currVal = 0;
        unordered_map<long long, int> map;
        map[0] = 1;
        backtracking(root, currVal, targetSum, count, map);
        return count;
    }

    void backtracking(TreeNode* root, long long currVal, int targetSum, int& count, unordered_map<long long, int>& map) {
        currVal += root -> val;
        int delta = currVal - targetSum;

        if (map.count(delta)) {
            count += map[delta];
        }
        map[currVal]++;
        if (root -> left != nullptr) backtracking(root -> left, currVal, targetSum, count, map);
        if (root -> right != nullptr) backtracking(root -> right, currVal, targetSum, count, map);
        //只考虑当前层，在遍历完左右子树后抹去当前值！！！之后左右子树都会放照这个模式递归进行
        map[currVal]--;
    }
};