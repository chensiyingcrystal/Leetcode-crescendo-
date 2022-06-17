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

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(), k = q.size();
            //double will not allow int to overflow
            double level_sum = 0;
            //bug: if use size below, size will decrease! so wrong answer if divided by size!
            while (k--) {
                TreeNode* temp = q.front();
                q.pop();
                level_sum += temp->val;
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            //get double by divide a double by int 
            double average = level_sum / size;
            ans.push_back(average);
        }
        return ans;
    }

};