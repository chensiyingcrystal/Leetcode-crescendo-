#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int> > ans;
        backtrack(candidates, target, 0, tmp, ans);
        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int first, vector<int>& tmp, vector<vector<int> >& ans) {
        int sum = accumulate(tmp.begin(), tmp.end(), 0);
        if (sum > target) return;
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }

        for (int i = first; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            backtrack(candidates, target, first, tmp, ans);
            tmp.pop_back();
        }
    }

};