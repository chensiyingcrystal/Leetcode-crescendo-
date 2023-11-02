#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <map>

//using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





class BSTree {
public:
    TreeNode *root;
    BSTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insertHelper(this->root, key);
    }

    bool search(int key) {
        return searchHelper(this->root, key);
    }

    void deleteNode(int key) {
        root = deleteHelper(this->root, key);
    }

    void preorderOutPut() {
        outputHelper(this->root);
    }

private: 
    TreeNode* insertHelper(TreeNode *node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        } 

        if (key < node->val) {
            node->left = insertHelper(node->left, key);
        } else {
            node->right = insertHelper(node->right, key);
        }
        return node;
    }

    bool searchHelper(TreeNode *node, int key) {
        if (node == nullptr) return false;
        if (node->val == key) return true;
        if (node->val < key) return searchHelper(node->right, key);
        return searchHelper(node->left, key);
    }

    TreeNode* deleteHelper(TreeNode *node, int& key) {
        if (node == nullptr) return nullptr;
        if (node->val == key) {
            if (node->left == nullptr && node->right == nullptr) {
                return nullptr;
            } else if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            } else {
                TreeNode* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                temp->left = node->left;
                return node->right;
            }


        } else if (node->val < key) {
            node->right = deleteHelper(node->right, key);
        } else {
            node->left = deleteHelper(node->left, key);
        }
        return node;

    }

    void outputHelper(TreeNode *node) {
        if (node == nullptr) return;
        outputHelper(node->left);
        std::cout << node->val << std::endl;
        outputHelper(node->right);
    }


};

TreeNode* constructBlancedBSTFromArray(std::vector<int> keys) {
    return constructHelper(keys, 0, keys.size() - 1);
}

TreeNode* constructHelper(std::vector<int>& keys, int start, int end) {
    if (end < start) return nullptr;
    int mid = start + (end - start) / 2;

    TreeNode* curr = new TreeNode(keys[mid]);
    curr->left = constructHelper(keys, start, mid - 1);
    curr->right = constructHelper(keys, mid + 1, end);
    return curr;

}



bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
}

bool isValidBSTHelper(TreeNode*& root, long minVal, long maxVal) {
    if (root == nullptr) {
        return true;
    }
    //check if has duplicate value in BST
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }

    return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}





int main() {
    BSTree* tree = new BSTree();
    std::vector<int> keys = {1, 2, 4, 6, 3, 5};
    for (int& key : keys) {
        tree->insert(key);
    }

    //tree->preorderOutPut();

    bool res = tree->search(5);
    std::cout << "search: " << std::boolalpha << res << std::endl;

    tree->deleteNode(5);
    tree->preorderOutPut();

    bool res2 = tree->search(5);
    std::cout << "search after delete: " << std::boolalpha << res2 << std::endl;
    

}