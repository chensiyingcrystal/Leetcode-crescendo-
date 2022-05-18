#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//这道题每次思维都卡在了，最大值不一定出现在经过当前node，那这样就无法连接下一个node
//解决办法：每次dfs return的都是左+当前节点或者右+当前节点（取两者大值和当前节点拼）
//用一个变量记录下左+当前节点+右产生的最大值即可 
    int maxPathSum(TreeNode* root) {

    }


};