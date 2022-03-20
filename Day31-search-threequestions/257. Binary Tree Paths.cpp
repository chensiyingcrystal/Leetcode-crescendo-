#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//自己写的解法
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<string> ans;
        vector<int> tmp;
        backtracking(root, tmp, ans);
        return ans;
    }

    void backtracking(TreeNode* node, vector<int>& tmp, vector<string>& ans) {
        //重要！！push进去后一定要pop出来！否则引用tmp时会出错！！
        if (node -> left == nullptr && node -> right == nullptr) {
            tmp.push_back(node -> val);
            ans.push_back(stringlist(tmp));
            tmp.pop_back();
            return;
        }

        tmp.push_back(node -> val);
        //要加入if
        //只对当层进行操作，不要管子树是什么情况，因为它也会经历一样的！！
        if (node -> left != nullptr) {
            backtracking(node -> left, tmp, ans);
        }
        if (node -> right != nullptr) {
            backtracking(node -> right, tmp, ans);
        }
        tmp.pop_back();
    }

    string stringlist(vector<int>& tmp) {
        string tmp_string;
        for (int i = 0; i < tmp.size() - 1; i++) {
            tmp_string += to_string(tmp[i]) + "->";
        }
        tmp_string += to_string(tmp[tmp.size() - 1]);
        return tmp_string;
    }

//另一种解法
    vector<string> v;
    void helper(TreeNode *root,string s){
        if (root == NULL){
            return;
        }
        s += to_string(root->val) + "->";
        if (root->left == NULL && root->right == NULL){
            s.pop_back();
            s.pop_back();
            v.push_back(s);
        }
        helper(root->left,s);
        helper(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        helper(root,s);
        return v;
    }
    
};

