#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
//bfs：strength: more straightforward
//method1: observing the rule and found that always FILO for the nodes on the next level
//therefore we can use a stack to store the child nodes
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int k = q.size();
            vector<int> tmp;
            stack<TreeNode*> s;

            while(k--) {
                TreeNode* node = q.front();
                q.pop();

                tmp.push_back(node -> val);

                if ((level + 1) % 2 != 0) {
                    if (node -> left != nullptr) s.push(node -> left);
                    if (node -> right != nullptr) s.push(node -> right);
                }
                else {
                    if (node -> right != nullptr) s.push(node -> right);
                    if (node -> left != nullptr) s.push(node -> left);
                }
            }
            ans.push_back(tmp);
            level++;

            while (!s.empty()) {
                TreeNode* tmp = s.top();
                s.pop();
                q.push(tmp);
            }  
        }
        return ans;
    }
//method2: use a normal vector to store nodes on the next level
//one way: add nodes in different order based on the even or odd property of the level
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            vector<TreeNode*> child;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node -> val);

                if (level % 2 == 0) {
                    if (node -> left) child.push_back(node -> left);
                    if (node -> right) child.push_back(node -> right);
                }
                else {
                    if (node -> right) child.push_back(node -> right);
                    if (node -> left) child.push_back(node -> left);
                }
            }
            ans.push_back(tmp);
            level++;

            for (int i = child.size() - 1; i >= 0; i--) {
                q.push(child[i]);
            }
        }
        return ans;
    }     
};
