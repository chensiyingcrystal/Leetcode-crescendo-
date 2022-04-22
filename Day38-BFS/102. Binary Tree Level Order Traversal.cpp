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
//method1: bfs
//bfs如何进行层序遍历？
//记录下每一层bfs的个数，优先循环完当前数目，即为当前层的node
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int k = q.size();
            vector<int> tmp;
            while (k--) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node -> val);
                
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
//method2: dfs
//前序遍历，top -> bottom, left -> right
//此题使用前序后序中序都是ac的，因为我们直接用level作为索引，所以是bottom-》top还是反过来并不重要
//手动添加level标记，用level指示index，将同层的放入同一个数组中
//由于dfs并不能知道总的level数，结果数组不能初始化，需要在level到达下一层时开创新的数组空间
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int> > ans;
        dfs(root, 0, ans);
        return ans;
        
    }

    void dfs(TreeNode* node, int level, vector<vector<int> >& ans) {
        //bug: not writing as: level > ans.size() - 1
        //ans.size() returns an unsigned int
        //so if you subtract 1 from an unsigned int, the answer will not be -1
        //instead it will be a very large number, which will lead to incorrect answer
        if (level == ans.size()) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        
        ans[level].push_back(node -> val);
        if (node -> left) dfs(node -> left, level + 1, ans);
        if (node -> right) dfs(node -> right, level + 1, ans);
    }

//再敲一遍bfs
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            vector<int> tmp;
            while(k--) {
                TreeNode* node = q.front();
                q.pop();

                tmp.push_back(node -> val);
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
//dfs
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int level, vector<vector<int> >& ans) {
        if (level == ans.size()) {
            vector<int> tmp;
            ans.push_back(tmp);
        }

        ans[level].push_back(root -> val);
        if (root -> left != nullptr) dfs(root -> left, level + 1, ans);
        if (root -> right != nullptr) dfs(root -> right, level + 1, ans);
    }
};
