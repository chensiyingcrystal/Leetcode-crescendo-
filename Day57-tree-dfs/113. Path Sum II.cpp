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

    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return {};
        vector<vector<int> > ans;
        vector<int> tmp;
        backtrack(root, targetSum, ans, tmp);
        return ans;
    }
    
    void backtrack(TreeNode* root, int targetSum, vector<vector<int> >& ans, vector<int>& tmp) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == targetSum) {
                tmp.push_back(root->val);
                //!!!push a vector into a vector
                //contains copying a vector and put its address(the first element's address) into the result vector<vector<int> >
                //This costs o(n)
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        
        tmp.push_back(root->val);
        if (root->left != NULL) {
            backtrack(root->left, targetSum - root->val, ans, tmp);
        }
        if (root->right != NULL) {
            backtrack(root->right, targetSum - root->val, ans, tmp);
        }
        tmp.pop_back();
    }
//what if we don't require the path start from the root and end at leaf
//Case1: start from root but not necessarily end at leaf
    vector<vector<int> > pathSumRootToNode(TreeNode* root, int targetSum) {
        
    }

//Case2: start from any node but must end at leaf

//Case3: no limitation on any of the ends

};