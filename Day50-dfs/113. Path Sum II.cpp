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
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;
        vector<int> tmp;
        int nodeSum = 0;
        backtracking(root, nodeSum, targetSum, tmp, ans);
        return ans;
    }

    void backtracking(TreeNode* root, int& nodeSum, int targetSum, vector<int>& tmp, vector<vector<int> >& ans) {
        if (root -> left == nullptr && root -> right == nullptr) {
            nodeSum += root -> val;
            tmp.push_back(root -> val);
            if (nodeSum == targetSum) {
                ans.push_back(tmp);
            }
            return;
        }

        nodeSum += root -> val;
        tmp.push_back(root -> val);
        
        if (root -> left != nullptr) {
            backtracking(root -> left, nodeSum, targetSum, tmp, ans);
            nodeSum -= (root -> left) -> val;
            tmp.pop_back();
        }

        if (root -> right != nullptr) {
            backtracking(root -> right, nodeSum, targetSum, tmp, ans);
            nodeSum -= (root -> right) -> val;
            tmp.pop_back();
        }
    }

};