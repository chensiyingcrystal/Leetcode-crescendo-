#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
//排列问题就是：不能重复选自己，除了自己之外其他人都可以选，不同的顺序算一种不同排列
//所以每到一个点，只要排除掉自己未被访问过（没有duplicates时）和自己的index未被访问过（有duplicates时）
//其他的需要用for循环确定；注意自己本身也应写入for循环
//自己写的：时间复杂度高，find耗时o（n）; 改成set后时间复杂度降低
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> tmp;
        vector<int> visited_index(nums.size());
        set<vector<int> > visited;
        backtracking(nums, 0, tmp, ans, visited, visited_index);
        return ans;
    }

    void backtracking(vector<int>& nums, int i, vector<int>& tmp, vector<vector<int> >&ans, 
    set<vector<int> >& visited, vector<int>& visited_index) {
        if (tmp.size() == nums.size()) {
            if (visited.find(tmp) == visited.end()) {
                ans.push_back(tmp);
                visited.insert(tmp);
            }
            return;
        }
        
        //这里主体要写到循环里，因为从第一个数字开始就有n种选择
        for (int j = 0; j < nums.size(); j++) {
            if (visited_index[j]) continue;
            tmp.push_back(nums[j]);
            visited_index[j] = 1;
            backtracking(nums, j, tmp, ans, visited, visited_index);
            visited_index[j] = 0;
            tmp.pop_back();
        }
    }
};

