#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }
    //暴力解法 回溯，类似79题
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //创建结果表
        vector<vector<int> > ans;
        const int m = heights.size();
        const int n = heights[0].size();
        //对每个格子遍历，看能不能走，如果能的话，就加入结果中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlow(heights, i, j, matrix[i][j]) == 3) {
                    ans.push_back(i, j);
                }
            }
        }
        return ans;
    }

private:
    int canFlow(vector<vector<int>>& heights, int i, int j, int h) {
        const int m = heights.size();
        const int n = heights[0].size();
        //建立回溯函数
            //判断边界条件(注意这道问题中，存在流入P，流入A，和不能流入三种情况)
        if (i < 0 || j < 0) return 1;
        if (i > m - 1 || j > n - 1) return 2;
        if (heights[i][j] > h) return 0;
            //对当前点进行标记
        int tmp = heights[i][j];
        heights[i][j] = INT_MAX;
            //对当前点的邻居进行检查
        int result = canFlow(heights, i + 1, j, tmp) || canFlow(heights, i - 1, j, tmp) || 
                     canFlow(heights, i, j + 1, tmp) || canFlow(heights, i, j - 1, tmp);
            //返回当前点的标记
        heights[i][j] = tmp;
        return result;
    }
};

int main() {
    return 0;
}