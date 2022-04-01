#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        bool flag = true;
        backtrack(k, 1, n, temp, ans, flag);
        return ans;
    }

    void backtrack(int k, int first, int target, vector<int>& temp, vector<vector<int> >& ans, bool& flag) {
        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if (temp.size() == k) {
            if (target > 0) return;
            if (target < 0) {
                flag = false;
                return;
            }
        }

        if (temp.size() != k) {
            if (target <= 0) {
                flag = false;
                return;
            }
        }

        for (int x = first; x <= 9; x++) {
            temp.push_back(x);
            backtrack(k, x + 1, target - x, temp, ans, flag);
            temp.pop_back();
            //flag传引用，且需要修改状态
            if (flag == false) {
                flag = true;
                break;
            }
        }        
    }

//简化代码，不使用flag的情况
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        backtrack(k, 1, n, temp, ans);
        return ans;
    }

    void backtrack(int k, int first, int target, vector<int>& temp, vector<vector<int> >& ans) {
        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if (temp.size() == k || target < 0) {
            return;
        }

        for (int x = first; x <= 9; x++) {
            temp.push_back(x);
            backtrack(k, x + 1, target - x, temp, ans);
            temp.pop_back();
        }        
    }
};