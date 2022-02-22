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
//第一遍写的：时间o(N) 空间 除了栈空间，还要使用数组的空间o(N)
    int kthSmallest(TreeNode* root, int k) {
        vector<int> count;
        helper(root, count);
        //不需要循环
        // for (int i = 0; i < count.size(); i++) {
        //     //bug：不能只在if内部返回，函数要有返回值
        //     if (i + 1 == k) result = count[i];
        // }
        return count[k - 1];
    }

    void helper(TreeNode* node, vector<int>& count) {
        if (node == NULL) return;

        helper(node -> left, count);
        count.push_back(node -> val);
        helper(node -> right, count);
    }

//第二遍：传参数count
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result;
        helper(root, count, k, result);
        return result;
        
    }

    void helper(TreeNode* node, int& count, int& k, int& result) {
        if (node == NULL) return;
    
        helper(node -> left, count, k, result);
        //bug：count的程序不能错！！到了当前值，先加1，再判断是不是k
        //这段就是helper函数的操作主体，左右都要在这里进行！！！
        count += 1;
        if (count == k) result = node -> val;
        helper(node -> right, count, k, result);
    }

};