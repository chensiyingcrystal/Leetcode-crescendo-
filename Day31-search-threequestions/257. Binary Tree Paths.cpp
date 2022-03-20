#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//自己写的解法
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<string> ans;
        vector<int> tmp;
        backtracking(root, tmp, ans);
        return ans;
    }

    void backtracking(TreeNode* node, vector<int>& tmp, vector<string>& ans) {
        //重要！！push进去后一定要pop出来！否则引用tmp时会出错！！
        if (node -> left == nullptr && node -> right == nullptr) {
            tmp.push_back(node -> val);
            ans.push_back(stringlist(tmp));
            tmp.pop_back();
            return;
        }

        tmp.push_back(node -> val);
        //要加入if
        //只对当层进行操作，不要管子树是什么情况，因为它也会经历一样的！！
        if (node -> left != nullptr) {
            backtracking(node -> left, tmp, ans);
        }
        if (node -> right != nullptr) {
            backtracking(node -> right, tmp, ans);
        }
        tmp.pop_back();
    }

    string stringlist(vector<int>& tmp) {
        string tmp_string;
        for (int i = 0; i < tmp.size() - 1; i++) {
            tmp_string += to_string(tmp[i]) + "->";
        }
        tmp_string += to_string(tmp[tmp.size() - 1]);
        return tmp_string;
    }

//另一种解法,不需要建立数组再转string,但是这里string path就需要复制传值，而不是引用传值！！
//1.不能用模板解决一切！空子和叶子都需要在递归的base case中考虑，其中空子直接返回，而叶子需要把结果push进去
//2.传引用和传复制的区别：传引用的话必须使用回溯，即要返回修改状态，然而在string中操作非常低效，因此传复制
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        helper(root, path, paths);
        return paths;

    }

    void helper(TreeNode* node, string path, vector<string>& paths) {
        if (node == nullptr) return;
        if (node -> left == nullptr && node -> right == nullptr) {
            path += to_string(node -> val);
            paths.push_back(path);
        }
        path += to_string(node -> val) + "->";
        helper(node -> left, path, paths);
        helper(node -> right, path, paths);
    }
    
};

