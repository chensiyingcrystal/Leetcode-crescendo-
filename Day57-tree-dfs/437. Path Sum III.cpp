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
//Solution: prefix sum
//Advantage: save many redundant and repetitive steps and reduce time complexity
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        unordered_map<long, int> map;
        //important: initializing the map; what if the root value is equal with targetSum?
        map[0] = 1;
        int count = 0;
        dfs(root, targetSum, 0, map, count);
        return count;
    }
    
    void dfs(TreeNode* root, int targetSum, long nodeSum, unordered_map<long, int>& map, int& count) {
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
//Solution2: more intuitive, clear, direct way to think about this problem yet requires more time
//idea: break into subproblem: define one of the end and calculate all the other ends
//total count = sum(start from root and end at any node) + sum(start from sub-nodes of root and end at any node);
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        int count = 0;
        dfs(root, (long long)targetSum, count);
        //recursive case
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
//this function calculates all the possbile paths that sum up to target when start from the root
    void dfs(TreeNode* root, long long targetSum, int& count) {
        if (root == NULL) return;
        if (root->val == targetSum) {
            count++; // important: do not return now!
        }
        dfs(root->left, (long long)targetSum - root->val, count);
        dfs(root->right, (long long)targetSum - root->val, count);
    }
};