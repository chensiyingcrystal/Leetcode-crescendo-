#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

//optimized code
    int numIslands(vector<vector<char> >& grid) {
        // special case
        if (grid.empty()) return 0;
        // 纵横尺度
        const int n = grid.size();
        const int m = grid[0].size();
        //初始化队列，建立存储结果，访问标记
        queue<int> q;
        int islands = 0;
        vector<int> visited(n * m, 0);
        //上下左右四方向，放在循环外
        int row_arr[] = {-1, 1, 0, 0};
        int col_arr[] = {0, 0, -1, 1};
        //对每个格子进行bfs
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                //判断条件后再看是不是要进行bfs
                if (grid[i][j] == '1' && !visited[i * m + j]) {
                    //队列初始化，同时访问标记
                    q.push(i * m + j);
                    visited[i * m + j] = 1;
                    //开始队列循环
                    while (!q.empty()) {
                        //取出队列元素并且删除
                        int element = q.front();
                        q.pop();
                        //对队列的邻居进行操作
                        for(int x = 0; x < 4; x++) {
                            int row = element / m + row_arr[x];
                            int col = element % m + col_arr[x];
                            //对满足条件的邻居（在边界内，未访问过，为陆地）加入队列
                            if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && !visited[row * m + col]) {
                                q.push(row * m + col);
                                visited[row * m + col] = 1;
                            }
                        }
                    }
                    //计数器操作
                    islands += 1;
                }
            }
        }
        //返回计数器结果
        return islands;
    }


// //original code
//     int numIslands(vector<vector<char> >& grid) {
//         if (grid.empty()) return 0;
//         const int n = grid.size();
//         const int m = grid[0].size();
//         int islands = 0;
//         queue<vector<int> > q;
//         vector<vector<int> > visited(n, vector<int>(m, 0));
//         // int[] row_directions = new int[]{1, -1 , 0, 0};
//         // int[] column_directons = new int[]{0, 0, 1, -1};
//         vector<vector<int> > directions;
//         vector<int> up;
//         up.push_back(-1);
//         up.push_back(0);
//         vector<int> left;
//         left.push_back(0);
//         left.push_back(-1);
//         vector<int> down;
//         down.push_back(1);
//         down.push_back(0);
//         vector<int> right;
//         right.push_back(0);
//         right.push_back(1);
//         directions.push_back(up);
//         directions.push_back(left);
//         directions.push_back(down);
//         directions.push_back(right);
//         for(int i = 0; i < n; ++i) {
//             for(int j = 0; j < m; ++j) {
//                 if (grid[i][j] == '1' && !visited[i][j]) {
//                     vector<int> index;
//                     index.push_back(i);
//                     index.push_back(j);
//                     q.push(index);
//                     visited[i][j] = 1;
//                     while (!q.empty()) {
//                         vector<int> element = q.front();
//                         q.pop();
//                         for(int x = 0; x < 4; x++) {
//                             int row = element[0] + directions[x][0];
//                             int col = element[1] + directions[x][1];
//                             if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && !visited[row][col]) {
//                                 vector<int> new_index;
//                                 new_index.push_back(row);
//                                 new_index.push_back(col);
//                                 q.push(new_index);
//                                 visited[row][col] = 1;
//                             }
//                         }
//                     }
//                     islands += 1;
//                 }
//             }
//         }
//         return islands;
//     }
    
    

};

int main() {
    return 0;
}
    
    
