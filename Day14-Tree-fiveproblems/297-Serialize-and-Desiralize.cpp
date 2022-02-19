#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {


    }

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if (!tmp) result += '#';
            else result += to_string(tmp -> val);

            if (tmp) {
                q.push(tmp -> left);
                q.push(tmp -> right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }


};