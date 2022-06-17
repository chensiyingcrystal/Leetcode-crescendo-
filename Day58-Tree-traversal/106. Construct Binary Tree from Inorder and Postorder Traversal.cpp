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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size();
        int n = postorder.size();
        return helper(inorder, 0, m - 1, postorder, 0, n - 1);
    }

    TreeNode* helper(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end) {
        if (in_start > in_end) {
            return NULL;
        }

        int pivot;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == postorder[post_end]) {
                pivot = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(inorder[pivot]);
        int left_number = pivot - in_start;
        int right_number = in_end - pivot;
        root->left = helper(inorder, in_start, pivot - 1, postorder, post_end - left_number - right_number, post_end - right_number - 1);
        root->right = helper(inorder, pivot + 1, in_end, postorder, post_end - right_number, post_end - 1);
        return root;
    }


};