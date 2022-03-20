#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
//方法一：自己探索的，写了dfs
    vector<vector<int> > permute(vector<int>& nums) {
        //special case
        if (nums.empty()) return {};
        //create answer list
        vector<vector<int> > ans;
        //begin loop through nums to begin dfs
        for (int i = 0; i < nums.size(); i++) {
            vector<int> p;
            dfs(nums, i, p, 1, ans);
        }
        return ans;
    }

    void dfs(vector<int>& nums, int i, vector<int>& p, int height, vector<vector<int> >& ans) {
        if (height > nums.size() || find(p.begin(), p.end(), nums[i]) != p.end()) return;

        p.push_back(nums[i]);
        for (int j = 0; j < nums.size(); j++) {
            dfs(nums, j, p, height + 1, ans);
        }

        if (height == nums.size()) {
            ans.push_back(p);
        }
        
        p.pop_back();
    }
//方法二，用backtracking模版写
//排列问题就是：不能重复选自己，除了自己之外其他人都可以选，不同的顺序算一种不同排列
//所以每到一个点，只要排除掉自己未被访问过（没有duplicates时）和自己的index未被访问过（有duplicates时）
//其他的需要用for循环确定；注意自己本身也应写入for循环，因为从一开始就需要考虑到全部元素
    vector<vector<int> > ans;
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> temp;
        //bug： visited需要提前预定空间
        vector<int> visited(nums.size());
        backtrack(nums, temp, visited);
        return ans;
        
    }

    void backtrack(vector<int>& nums, vector<int>& temp, vector<int>& visited) {
        //ending condition：初始情况是否考虑？temp和nums都为空的时候
        if (temp.size() == nums.size() && !temp.empty()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            //如果不想使用这样的find（复杂度o（n）），也可以单独做一个数组记录数字是否出现过
            //push进temp就记录为出现了，推出来就取消记录
            if (visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i] = 1;
            backtrack(nums, temp, visited);
            temp.pop_back();
            visited[i] = 0;
        } 
    }
};
