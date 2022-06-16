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

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        unordered_map<int, int> map;
        //important: initializing the map; what if the root value is equal with targetSum?
        map[0] = 1;
        int count = 0;
        dfs(root, targetSum, 0, map, count);
        return count;
    }
    
    void dfs(TreeNode* root, int targetSum, long nodeSum, unordered_map<int, int>& map, int& count) {
        if (root == NULL) return;
        //important: keep the sum of nodes' val in the limitation of int
        nodeSum += (long)root->val;
        if (map.find(nodeSum - targetSum) != map.end()) {
            count += map[nodeSum - targetSum];
        }
        map[nodeSum]++;
        
        dfs(root->left, targetSum, nodeSum, map, count);
        dfs(root->right, targetSum, nodeSum, map, count);
        //important: must erase nodeSum from the map before going into the parellel subtree
        map[nodeSum]--;
    }
};