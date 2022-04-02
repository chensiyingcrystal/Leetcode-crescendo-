#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
/**分治问题的解决途径：
分解 -> 解决（触底）-> 合并（回溯）

void divid_merge(一个数组) {
  if (达到数组边界) return;
//相当于二叉树的后续遍历
  divid_merge(左半个数组);
  divid_merge(右半个数组);
  merge(左半个数组, 右半个数组);
}
*/
    vector<int> diffWaysToCompute(string expression) {
        const int n = expression.length();
        return helper(expression, 0, n - 1);
    }

    vector<int> helper(string& s, int start, int end) {
        vector<int> ans;
        //base case
        int length = end - start + 1;
        //bug: using s.length() is wrong
        if (length == 1  || length == 2) {
            //bug: using s is wrong
            ans.push_back(stoi(s.substr(start, length)));
            return ans;
        }
        //divide: find each operator and then divide according that
        for (int i = start; i <= end; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = helper(s, start, i - 1);
                vector<int> right = helper(s, i + 1, end);
                //then conquer
                for (int x = 0; x < left.size(); x++) {
                    for (int y = 0; y < right.size(); y++) {
                        switch(s[i]) {
                            case '+': ans.push_back(left[x] + right[y]); break;
                            case '-': ans.push_back(left[x] - right[y]); break;
                            case '*': ans.push_back(left[x] * right[y]); break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};