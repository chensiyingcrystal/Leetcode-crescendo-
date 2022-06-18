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

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int m = preorder.size();
        int n = postorder.size();
        return helper(preorder, 0, m - 1, postorder, 0, n - 1);
    }

    TreeNode* helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& postorder, 
                    int post_start, int post_end) {
        if (pre_start > pre_end) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        if (pre_start == pre_end) {
            root->left = NULL;
            root->right = NULL;
            return root;
        }

        int pivot;
        for (int i = post_start; i <= post_end; i++) {
            if (preorder[pre_start + 1] == postorder[i]) {
                pivot = i;
                break;
            }
        }

        int left_number = pivot - post_start + 1;
        root->left = helper(preorder, pre_start + 1, pre_start + left_number, postorder, post_start, pivot);
        root->right = helper(preorder, pre_start + left_number + 1, pre_end, postorder, pivot + 1, post_end - 1);
        return root;  
    }
};