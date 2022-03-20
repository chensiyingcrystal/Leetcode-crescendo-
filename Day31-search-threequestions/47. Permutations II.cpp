#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
//自己写的：时间复杂度高，find耗时o（n）; 改成set后时间复杂度降低
//因为sort是有序保存的，因此set的find耗时o（logn），而unordered_set的find耗时o(1)
//unordered_set不能存vector<int>
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
//推荐写法：剪枝
//对于重复元素剪枝我们可以想到的是做个预处理排序
//
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        //preprocessing
        sort(nums.begin(), nums.end());
        //result and visited mark
        vector<vector<int> > ans;
        vector<int> tmp;
        vector<int> visited_index(nums.size());
        backtrack(nums, 0, tmp, ans, visited_index);
        return ans;
    }

    void backtrack(vector<int>& nums, int i, vector<int>& tmp, vector<vector<int> >&ans, 
    vector<int>& visited_index) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        
        //这里主体要写到循环里，因为从第一个数字开始就有n种选择
        for (int j = 0; j < nums.size(); j++) {
            if (visited_index[j]) continue;
            //剪枝的关键：如果当前元素与前一个元素相等，且前一个元素未被访问过，则当前元素被剪
            //前一个元素在之前肯定被访问过，现在没有记录说明已经完成了backtrack的过程
            //以当前元素开始的排列肯定已经被考虑过了，因此减去即可
            if (j > 0 && nums[j] == nums[j - 1] && visited_index[j - 1] == 0) continue;
            tmp.push_back(nums[j]);
            visited_index[j] = 1;
            backtrack(nums, j, tmp, ans, visited_index);
            visited_index[j] = 0;
            tmp.pop_back();
        }
    }

//另一种自己写的,时间复杂度也不是很好
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> tmp;
        vector<int> visited_index(nums.size());
        unordered_set<string> visited;
        backtracking(nums, 0, tmp, ans, visited, visited_index);
        return ans;
    }

    void backtracking(vector<int>& nums, int i, vector<int>& tmp, vector<vector<int> >&ans, 
    unordered_set<string>& visited, vector<int>& visited_index) {
        if (tmp.size() == nums.size()) {
            string tmp_string = listTostring(tmp);
            if (visited.find(tmp_string) == visited.end()) {
                ans.push_back(tmp);
                visited.insert(tmp_string);
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

    string listTostring(vector<int>& tmp) {
        string ans = "";
        for (int& t : tmp) {
            ans += to_string(t);
        }
        return ans;
    }
};

