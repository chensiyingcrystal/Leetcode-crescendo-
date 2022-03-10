#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
//dfs写法一：控制条件前置
//此题前置写法和后置写法差别不大，但是如果将记录访问和结果的数组合并为一个，会很大地节省空间和时间
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& heights) {
        //first implement searching on nodes that can reach pacific ocean
        int m = heights.size(), n = heights[0].size();
        vector<vector<int> > pacific;
        //重要bug：visited这里一定要提前开辟好空间！！！不然访问出错
        vector<vector<int> > visited1(m, vector<int>(n));
        for (int i = 0, j = 0; j < heights[0].size(); j++) {
            if (!visited1[i][j]) {
                dfs(heights, i, j, visited1, pacific, heights[i][j]);
            }
        }

        for (int j = 0, i = 0; i < heights.size(); i++) {
            if (!visited1[i][j]) {
                dfs(heights, i, j, visited1, pacific, heights[i][j]);
            }
        }

        //implement searching nodes that can reach atlantic ocean
        vector<vector<int> > atlantic;
        vector<vector<int> > visited2(m, vector<int>(n));
        for (int i = heights.size() - 1, j = 0; j < heights[0].size(); j++) {
            if (!visited2[i][j]) {
                dfs(heights, i, j, visited2, atlantic, heights[i][j]);
            }
        }

        for (int j = heights[0].size() - 1, i = 0; i < heights.size(); i++) {
            if (!visited2[i][j]) {
                dfs(heights, i, j, visited2, atlantic, heights[i][j]);
            }
        }

        //find common elements in the pacific set and atalantic set
        vector<vector<int> > ans;
        
        for (auto& p : pacific) {
            for (auto& a : atlantic) {
                if (p == a) {
                    ans.push_back(p);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int> >& heights, int i, int j, vector<vector<int> >& visited, 
    vector<vector<int> >& output, int height) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if (visited[i][j] || heights[i][j] < height) return;

        visited[i][j] = 1;
        vector<int> element = {i, j}; 
        output.push_back(element);

        dfs(heights, i + 1, j, visited, output, heights[i][j]);
        dfs(heights, i - 1, j, visited, output, heights[i][j]);
        dfs(heights, i, j + 1, visited, output, heights[i][j]);
        dfs(heights, i, j - 1, visited, output, heights[i][j]);
    }
//访问标记和结果数组合二为一
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& heights) {
        //first implement searching on nodes that can reach pacific ocean
        int m = heights.size(), n = heights[0].size();
        vector<vector<int> > pacific(m, vector<int>(n));
        //重要bug：visited这里一定要提前开辟好空间！！！不然访问出错
        for (int i = 0, j = 0; j < heights[0].size(); j++) {
            if (!pacific[i][j]) {
                dfs(heights, i, j, pacific, heights[i][j]);
            }
        }

        for (int j = 0, i = 0; i < heights.size(); i++) {
            if (!pacific[i][j]) {
                dfs(heights, i, j, pacific, heights[i][j]);
            }
        }

        //implement searching nodes that can reach atlantic ocean
        vector<vector<int> > atlantic(m, vector<int>(n));
        for (int i = heights.size() - 1, j = 0; j < heights[0].size(); j++) {
            if (!atlantic[i][j]) {
                dfs(heights, i, j, atlantic, heights[i][j]);
            }
        }

        for (int j = heights[0].size() - 1, i = 0; i < heights.size(); i++) {
            if (!atlantic[i][j]) {
                dfs(heights, i, j, atlantic, heights[i][j]);
            }
        }

        //find common elements in the pacific set and atalantic set
        vector<vector<int> > ans;
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> element = {i, j};
                    ans.push_back(element);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int> >& heights, int i, int j, vector<vector<int> >& output, int height) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if (output[i][j] || heights[i][j] < height) return;

        output[i][j] = 1;

        dfs(heights, i + 1, j, output, heights[i][j]);
        dfs(heights, i - 1, j, output, heights[i][j]);
        dfs(heights, i, j + 1, output, heights[i][j]);
        dfs(heights, i, j - 1, output, heights[i][j]);
    }
//写法二：控制条件后置
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, 1, -1};

        vector<vector<int> > pacificAtlantic(vector<vector<int> >& heights) {
        //first implement searching on nodes that can reach pacific ocean
        int m = heights.size(), n = heights[0].size();
        vector<vector<int> > pacific;
        //重要bug：visited这里一定要提前开辟好空间！！！不然访问出错
        vector<vector<int> > visited1(m, vector<int>(n));
        for (int i = 0, j = 0; j < heights[0].size(); j++) {
            if (!visited1[i][j]) {
                dfs(heights, i, j, visited1, pacific);
            }
        }

        for (int j = 0, i = 0; i < heights.size(); i++) {
            if (!visited1[i][j]) {
                dfs(heights, i, j, visited1, pacific);
            }
        }

        //implement searching nodes that can reach atlantic ocean
        vector<vector<int> > atlantic;
        vector<vector<int> > visited2(m, vector<int>(n));
        for (int i = heights.size() - 1, j = 0; j < heights[0].size(); j++) {
            if (!visited2[i][j]) {
                dfs(heights, i, j, visited2, atlantic);
            }
        }

        for (int j = heights[0].size() - 1, i = 0; i < heights.size(); i++) {
            if (!visited2[i][j]) {
                dfs(heights, i, j, visited2, atlantic);
            }
        }

        //find common elements in the pacific set and atalantic set
        vector<vector<int> > ans;
        
        for (auto& p : pacific) {
            for (auto& a : atlantic) {
                if (p == a) {
                    ans.push_back(p);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int> >& heights, int i, int j, vector<vector<int> >& visited, 
    vector<vector<int> >& output) {
        visited[i][j] = 1;
        vector<int> element = {i, j}; 
        output.push_back(element);
        
        for (int x = 0; x < 4; x++) {
            int new_i = i + row[x];
            int new_j = j + col[x];
            if (new_i >= 0 && new_i < heights.size() && new_j >= 0 && new_j < heights[0].size()
                && !visited[new_i][new_j] && heights[new_i][new_j] >= heights[i][j]) {
                    dfs(heights, new_i, new_j, visited, output);
            }
        }
    }
};