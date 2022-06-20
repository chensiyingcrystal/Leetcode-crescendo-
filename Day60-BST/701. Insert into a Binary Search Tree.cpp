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
//not very hard but easy to make mistake
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //bug: always remember to check if root is null;
        //if not adding this line, what gets modified is curr's pointer in the dfs function not root
        if (root == NULL) return new TreeNode(val);
        //here we should avoid using another pointer unless this is an iterative problem
        TreeNode* curr = root;
        dfs(curr, val);
        return root;
    }
//bug:here if we do not use '&' to represent the reference, what actually gets modified is the copied curr pointer
    void dfs(TreeNode*& curr, int val) {
        if (curr == NULL) {
            curr = new TreeNode(val);
            return;
        }
        if (curr->val < val) {
            dfs(curr->right, val);
            return;
        }
        dfs(curr->left, val);
    }
//optimized 
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        dfs(root, val);
        return root;
    }
//如果只是对root指向的node进行操作，那么用指针即可；如果是要对指针本身进行操作（如改变指针指向的节点的左右指针）
//那么要记住这种修改并且最后返回原指针，就一定要用索引！！！
//这种情况下每次传参数，里面的root对应的都是原来传入时的那个指针，并非copied的指针
    void dfs(TreeNode*& root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            //bug: do not forget to return here in the base case!!
            return;
        }
        return root->val < val? dfs(root->right, val) : dfs(root->left, val);
    }
            
};