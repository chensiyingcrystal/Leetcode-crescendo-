#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        vector<vector<int> > ans;
        bool flag = false;
        vector<int> visited(candidates.size());
        backtrack(candidates, target, 0, tmp, ans, flag, visited);
        return ans;
    }
    
    void backtrack(vector<int>& candidates, int target, int first, vector<int>& tmp, vector<vector<int> >& ans, bool& flag, vector<int>& visited) {
        if (target < 0) {
            flag = true;
            return;
        }
        if (target == 0) {
            ans.push_back(tmp);
            flag = true;
            return;
        }

        for (int i = first; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && visited[i - 1] == 0) continue;
            tmp.push_back(candidates[i]);
            visited[i] = 1;
            backtrack(candidates, target - candidates[i], i + 1, tmp, ans, flag, visited);
            tmp.pop_back();
            visited[i] = 0;
            //bug:传的flag需要是引用，但是修改过一次之后要改回原状态再break（不是continue）
            //更好的做法可以是在backtrack前就判定，如果target - candidates[i] < 0,则break
            if (flag) {
                flag = false;
                break;
            }
        }
    }

};