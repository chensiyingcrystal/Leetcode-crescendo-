#include <unordered_map>
#include <queue>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>

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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int n = inorder.size();
        return helper(preorder, 0, m - 1, inorder, 0, n - 1);
    }

    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return NULL;
        }
        if (pre_start == pre_end) {
            TreeNode* temp = new TreeNode(preorder[pre_start]);
            return temp;
        }
        
        int pivot;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == preorder[pre_start]) {
                pivot = i; 
                break;
            }
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        int left_number = pivot - in_start;

        root->left = helper(preorder, pre_start + 1, pre_start + left_number, inorder, in_start, pivot - 1);
        root->right = helper(preorder, pre_start + left_number + 1, pre_end, inorder, pivot + 1, in_end);
        return root;
    }
//Here we notice that everytime we call helper function, we need to find the pivot once
//However, this operation could be reduced to o(n); We need to take advantage of unique values in this tree
//Using hash map to establish a relationship between the value and the index
//Time complexity : O(N)O(N).
//Building the hashmap takes O(N)time; Building the tree also takes O(N) time since it is called once for each of the N nodes, giving a total of O(N).
//Space complexity : O(N).Building the hashmap and storing the entire tree each requires O(N)memory. 
//The size of the implicit system stack used by recursion calls depends on the height of the tree, which is O(N) in the worst case and O(logN) on average. 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int n = inorder.size();

        //construct a hash map 
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }

        return helper(preorder, 0, m - 1, 0, map);
    }

    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end, int in_start, unordered_map<int, int>& map) {
        if (pre_start > pre_end) {
            return NULL;
        }

        int pivot = map[preorder[pre_start]], left_number = pivot - in_start;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        root->left = helper(preorder, pre_start + 1, pre_start + left_number, in_start, map);
        root->right = helper(preorder, pre_start + left_number + 1, pre_end, pivot + 1, map);
        return root;
    }
};