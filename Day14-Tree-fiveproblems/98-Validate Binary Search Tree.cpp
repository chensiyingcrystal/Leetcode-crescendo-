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
//yifan's edition(same)
    // bool isValidBST(TreeNode* root, long& min_v, long& max_v) {
    //         if (root == nullptr) {
    //             return true;
    //         }

    //         if (root->left == nullptr && root->right == nullptr) {
    //             min_v = root->val;
    //             max_v = root->val;
    //             return true;
    //         }
            
    //         long min_l_v = (long)INT_MAX+1;
    //         long max_l_v = (long)INT_MIN-1;
    //         long min_r_v = (long)INT_MAX+1;
    //         long max_r_v = (long)INT_MIN-1;

    //         if (!isValidBST(root->left, min_l_v, max_l_v)) {
    //             return false;
    //         }
    //         if (!isValidBST(root->right, min_r_v, max_r_v)) {
    //             return false;
    //         }
    //         if (max_l_v >= root->val) {
    //             return false;
    //         }
    //         if (root->val >= min_r_v) {
    //             return false;
    //         }    

    //         min_v = min(min_l_v, (long) root->val);
    //         max_v = max(max_r_v, (long) root->val);
    //         return true;
    //     }
    
    // bool isValidBST(TreeNode* root) {
    //     long min_v, max_v;
    //     return isValidBST(root, min_v, max_v);
    //     }

    
//理解题意：要满足二叉树的特点必须：
    //左支所有值要小于root值，同时右支所有值要大于root值
    //左支和右支都是BST -> 左支的左下方所有值要小于该值，右下方所有值要大于该值，但是整体所有值都要小于root值
//思路如何转化成代码？
    //技巧1: 对于此类左节点的要小于node本身值，下面所有系列都要满足该条件，可以使用最大值最小值来判断
    //技巧2：利用深度优先搜索的特点，往下搜索，最先获得最底层的值，因此可以传参数从底层至上进行更新
//画图过程中的参悟（从base case开始画起，比如leaf到上方的节点是什么情况？）
    //每个node而言，left_max < node_val && right_min > node_val
    //该node传上去时的最小最大值：min = left_min, max = right_max（所以对于每个节点而言需要四个变量记录）
    //犯错误：该node在传上去时，直接认为包含该节点本身在内的整体最小值就是其左支最小值，最大值就是右支最大值
    //错误原因：node的值就一定是中间值吗？那么对于只有右支或只有左支的节点而言呢？其上限下限又是多少？
//转化成代码学习的几点
    //分清楚哪些变量是每轮在更新，哪些是需要从底层至上累积更新的，要分开设置（此题共需要设置六个变量）
    //每一轮需要存节点下方左支的最大最小值和右支的最大最小值，然后用节点本身和左支最小值更新全体最小值
    //用节点本身和右支最大值更新全体最大值
    //考虑base case的时候不要乱，写完之后回头看再确定要不要保留
    //步骤要考虑清晰：首先应该展开搜索，让下层最大最小值进行更新后，同时判断下层是不是BST，再判断该层是否满足
    //如果以上都满足，再对全体值进行更新。两个功能同时进行时间效率明显更高，应该设计成为一个函数。
   
    bool isValidBST(TreeNode* root) {
        long max_val, min_val;
        return helper(root, max_val, min_val);
    }

    bool helper(TreeNode* node, long& max_val, long& min_val) {
        //base case: for null node, don't need to revise max and min, and return true
        if (node == NULL) return true;
        //another base case: may not need, but you can writer first to clear your mind
        if (node -> left == NULL && node -> right == NULL) {
            //赋值的时候会自动转换
            max_val = node -> val;
            min_val = node -> val;
            return true;
        }
        //步骤思考的时候可以利用base case的上方节点为例子进行验证和思考
        //第一件事: 我们需要获取left_max, left_min, right_max and right_min
            //重点：从底层获取的过程中，左右两支的最大最小值确定了，因此这步就需要进行递归
            //细节：这四个值对于每轮的节点都不一样，因此每轮都需要新建四个值
            //细节：对于最大最小值更新的情况，一般需要设置极小值，极大值作为初始值
        //第二件事：同时确定左右两支都是BST，这步是与从底层更新同步进行的，但是这步可以作为熔断机制
            //重点：理清这里的逻辑，是排除法，如果子树是true，不一定就是return true
        //第三件事：判断当前节点当前两侧值是不是满足要求（这步也是排除法，因为满足要求了还要进行下一步更新不能立即返回true）
        //第四件事：以上都满足的条件下，用当前值和左支最小值更新全体最小值，当前值和右支最大值更新全体最大值
        
        //first thing, second thing
        //bug点，测试数据node的val可能等于32位signed最小值或最大值
        //INT_MIN和INT_MAX的值是32小值和最大值
        //赋值是会自动转化，但是由于这里要加1和减1，如果不先将INT转成大一level的，加1减1后就会溢出
        //可以转化为int64_t或者long
        long left_max = (long) INT_MIN - 1;
        long right_max = (long) INT_MIN - 1;
        long left_min = (long) INT_MAX + 1;
        long right_min = (long) INT_MAX + 1;

        if (!helper(node -> left, left_max, left_min)) return false;
        if (!helper(node -> right, right_max, right_min)) return false;

        //third thing
        //bug点 不能等于
        //比大小的时候会自动转化，所以这里不需要把node_val转化
        if (left_max >= node -> val || right_min <= node -> val) return false;

        //fourth thing
        //这里要转，因为max和min只能同类型的比大小
        max_val = max(right_max, (long) node -> val);
        min_val = min(left_min, (long) node -> val);
        return true;

    }

//solution2: lnr inorder traversing, using node
    bool isValidBST(TreeNode* root, TreeNode*& pre) {
            if (root == nullptr) {
                return true;
            }
            if (!isValidBST(root->left, pre)) {
                return false;
            }
            if (pre != nullptr && pre->val >= root->val) {
                return false;
            }
            pre = root;
            return (isValidBST(root->right, pre));
        }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return isValidBST(root, pre);
    }

//solution2: inorder - using long
    bool isValidBST(TreeNode* root) {
        long pre = (long) INT_MIN - 1;
        return helper(root, pre);
    }
//bug点：important！！！从头到尾沿用的pre，需要写&！！！
    bool helper(TreeNode* root, long& pre) {
        if (root == NULL) return true;

        if (!helper(root -> left, pre)) return false;
        if (pre != (long) INT_MIN - 1 && root -> val <= pre) return false;
        pre = root -> val;
        return helper(root -> right, pre);
    }

//solution3：官方solution 不会
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }




};