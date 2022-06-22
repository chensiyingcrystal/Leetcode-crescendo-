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
//dfs design: do not hesitate using which model
//    //每个点的信息都是独特的，而且根节点要利用左右节点的信息来更新的时候就用return
    //如果这些信息都是用来修改global variable的，就传引用
//In this case, using reference is pretty much more straightforward
//use a count to count number(do not hesitate to use count++ or k--, it's the same, depending on 
  //you feel using which is more comfortable)
//and use a ans's reference to record answer
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, count = 0;
        dfs(root, k, ans, count);
        return ans;
    }
    void dfs(TreeNode* root, int k, int& ans, int& count) {
        if (root == NULL) return;
        dfs(root->left, k, ans, count);
        if (ans != -1) return;
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }
        dfs(root->right, k, ans, count);
    }
};