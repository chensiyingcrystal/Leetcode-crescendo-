#include <iostream>
#include <vector>
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
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if (!tmp) {
            //bug: use space to split words, since not all value are from 0-9
                result += "# ";
                continue;
            }
            //add space to split
            else result += to_string(tmp -> val) + " ";

            q.push(tmp -> left);
            q.push(tmp -> right);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;

        //tricks: use stringsteam to split string against spaces
        vector<string> splitData;
        stringstream ss(data);
        string word;
        while (ss >> word) {
            splitData.push_back(word);
        }

        //begin bfs
        queue<TreeNode*> q;
        //trick: use stoi to convert string to int
        TreeNode* root = new TreeNode(stoi(splitData[0], 0, 10));
        q.push(root);

        for (int i = 1; i < splitData.size(); i += 2) {
            TreeNode* node = q.front();
            q.pop();
            
            //bug: splitData's elements are string, must extract its element, which is character
            if (splitData[i][0] != '#') {
                node -> left = new TreeNode(stoi(splitData[i], 0, 10));
                q.push(node -> left);
            }
            if (splitData[i + 1][0] != '#') {
                node -> right = new TreeNode(stoi(splitData[i + 1], 0, 10));
                q.push(node -> right);
            }
        }
        return root;
    }


};