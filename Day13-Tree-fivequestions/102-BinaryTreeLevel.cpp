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
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

//solution1
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int> > result;
        q.push(root);
        while (!q.empty()) {
            vector<int> elements;
            //bug: q.size() will be changing, so each time before iteration, save q.size() value;
            int level = q.size();
            //use iteration to group each level's nodes
            for (int i = 0; i < level; i++) {
                TreeNode* cur = q.front();
                q.pop();
                //if result is not initialized space, not allowed to use result[i].push_back()
                elements.push_back(cur -> val);
                //bug
                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
            }
            result.push_back(elements);
        }
        return result;
    }

//solution2
vector<vector<int> > levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int> > result;
        q.push(root);
        int new_count = 1;
        while (!q.empty()) {
            vector<int> elements;
            int pre_count = new_count;
            new_count = 0;
            for (int i = 0; i < pre_count; i++) {
                TreeNode* cur = q.front();
                q.pop();
                //if result is not initialized space, not allowed to use result[i].push_back()
                elements.push_back(cur -> val);
                //bug
                if (cur -> left) {q.push(cur -> left); new_count++;}
                if (cur -> right) {q.push(cur -> right); new_count++;};
            };
            result.push_back(elements);
        }
        return result;
    }

//solution3 time: o(n), space o(n)
vector<vector<int> > levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, int> > q;
        vector<vector<int> > result;
        q.push(make_pair(root, 0));
        int current_level = 0;
        while (!q.empty()) {
            vector<int> elements;
            while(q.front().second == current_level) {
                TreeNode* cur = q.front().first;
                q.pop();
                //if result is not initialized space, not allowed to use result[i].push_back()
                elements.push_back(cur -> val);
                //bug
                if (cur -> left) q.push(make_pair(cur -> left, current_level + 1)); 
                if (cur -> right) q.push(make_pair(cur -> right, current_level + 1)); 
            };
            current_level ++;
            result.push_back(elements);
        }
        return result;
    }

//solution 4: recursive
vector<vector<int> > levelOrder(TreeNode* root) {
    

    }
};