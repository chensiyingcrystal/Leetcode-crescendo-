#include <unordered_set>
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

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //1. preprocessing: convert to_delete to hashset to do o(1) search each time
        // unordered_set<int> delete_set;
        // for (int& num : to_delete) {
        //     delete_set.insert(num);
        // }
        //make code concise
        unordered_set<int> delete_set(to_delete.begin(), to_delete.end());
        
        //2. dfs finding all islands and add them to the result
        vector<TreeNode*> ans;
        dfs(root, ans, true, delete_set);
        return ans;
        
    }
    //use flag here to mark if it's a root of an island
    void dfs(TreeNode*& root, vector<TreeNode*>& ans, bool flag, unordered_set<int>& delete_set) {
        if (root == NULL) return;
        if (delete_set.find(root->val) != delete_set.end()) {
            dfs(root->left, ans, true, delete_set);
            dfs(root->right, ans, true, delete_set);
            root = NULL;
        }
        else {
            dfs(root->left, ans, false, delete_set);
            dfs(root->right, ans, false, delete_set);
            if (flag) ans.push_back(root);
        }
    }
};