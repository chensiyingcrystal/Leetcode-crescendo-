#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        int total = 0;
        backtrack(candidates, target, total, temp, ans);
        return ans;
        
    }

    void backtrack(vector<int>& candidates, int target, int total, vector<int>& temp, vector<vector<int> > ans) {
        if (total == target) {
            ans.push_back(temp);
            return;
        }
    }
};