#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }
    // 优化方法 dfs，从边界出发向中间进行深度优先搜索， 对每个元素进行记录，减少时间复杂度
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //special case, dimension
        if (heights.empty()) return {};
        const int m = heights.size();
        const int n = heights[0].size();

        //建立记录结果的容器
        vector<vector<int>> p(m, vector<int>(n, 0));
        vector<vector<int>> a(m, vector<int>(n, 0));

        //对首行和末行每个元素进行dfs搜索
        for (int x = 0; x < n; x++) {
            dfs(heights, 0, x, 0, p);
            dfs(heights, m - 1, x, 0, a);
        }

        //对首列和末列每个元素进行dfs搜索
        for (int x = 0; x < m; x++) {
            dfs(heights, x, 0, 0, p);
            dfs(heights, x, n - 1, 0, a);
        }
            
        //将dfs结果的交集存入最终结果中
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(j);
                    ans.push_back(pair);
                }
            }
        }
        //返回结果
        return ans;
    }

private:
//bug点：一定要传引用！！
    void dfs(vector<vector<int>>& heights, int i, int j, int h, vector<vector<int>>& result) {
        const int m = heights.size();
        const int n = heights[0].size();

        int row_arr[] = {1, -1, 0, 0};
        int col_arr[] = {0, 0, 1, -1};

        //不对其展开搜索的情况(出界，已访问或者高度不满足要求)
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1) return;
        if (result[i][j] || h > heights[i][j]) return;

        //满足条件下，记录当前元素的值（同时起到标记的作用）
        result[i][j] = 1;
        // 对其邻居进行搜索（与回溯的区别：当前的值不由邻居决定，而是对邻居进行深度搜索）
        // dfs(heights, i + 1, j, heights[i][j], result);
        // dfs(heights, i - 1, j, heights[i][j], result);
        // dfs(heights, i, j + 1, heights[i][j], result);
        // dfs(heights, i, j - 1, heights[i][j], result);
        for(int x = 0; x < 4; x++) {
            dfs(heights, i + row_arr[x], j + col_arr[x], heights[i][j], result);
        }
    }




    //暴力解法回溯，类似79题, 对每个元素遍历进行检查,时间复杂度是4^(mn)
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& heights) {
        //创建结果表
        vector<vector<int> > ans;
        const int m = heights.size();
        const int n = heights[0].size();
        //对每个格子遍历，看能不能走，如果能的话，就加入结果中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canFlow(heights, i, j, heights[i][j]) == 3) {
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(j);
                    ans.push_back(pair);
                }
            }
        }
        return ans;
    }

private:
    int canFlow(vector<vector<int> >& heights, int i, int j, int h) {
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
            //对当前点的邻居进行检查（按位或的表达式，转化成二进制后对每个digit或运算）
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