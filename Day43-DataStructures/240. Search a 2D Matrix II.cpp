#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
//这道题直觉感是使用二分，但是如何使用却需要分解问题的能力
//错误思路：想着沿着四周分别进行二分（从左上角汇聚到右下角）但二分的使用前先存为数组（消耗时间on，得不偿失）
//学习技巧：如何按照diag来移动（一层循环控制i就好了，因为此时row和col都为i） + 二分要用index来做！！！
//利用bool值来控制横着走还是竖着走
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int diag = min(m, n);
        //break into two parts! not completing one time!
        for (int i = 0; i < diag; i++) {
            bool ans = binarySearch(matrix, target, m, n, i, true) 
                         || binarySearch(matrix, target, m, n, i, false);
            if (ans) return true;
        }
        return false;

    }

    bool binarySearch(vector<vector<int> >& matrix, int target, int m, int n, int i, bool horizontal) {
        //直接用index控制low和high的变化
        int low = i, high;
        if (horizontal) {
            high = n - 1; 
        }
        else {
            high = m - 1;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_number;
            if (horizontal) {
                mid_number = matrix[i][mid];
            }
            else {
                mid_number = matrix[mid][i];
            }
            if (mid_number == target) return true;
            else if (mid_number > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
//自己的另一种思路，利用左上角点和右下角点的范围进行控制，加速判断，像剥洋葱一样
//太容易写错，不推荐
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        pair<int, int> left(0, 0), right(m - 1, n - 1);
        while (left.first <= right.first && left.second <= right.second) {
            int low = matrix[left.first][left.second], high = matrix[right.first][right.second];
            if (target < low || target > high) return false;
            //需要直接传角点进去
            bool ans = binarySearch(matrix, target, m, n, left, true, true) 
                        || binarySearch(matrix, target, m, n, left, false, true)
                        || binarySearch(matrix, target, m, n, right, true, false)
                        || binarySearch(matrix, target, m, n, right, false, false);
            if (ans) return true;
            left.first++;
            left.second++;
            right.first--;
            right.second--;
        }
        return false;
    }

    bool binarySearch(vector<vector<int> >& matrix, int target, int m, int n, pair<int, int> point, bool horizontal, bool forward) {
        //直接用index控制low和high的变化
        int low, high;
        if (forward) {
            if (horizontal) {low = point.second; high = n - 1 - point.second;} 
            else {low = point.first; high = m - 1 - point.first;}
        }
        else {
            if (horizontal) {low = n - 1 - point.second; high = point.second;}
            else {low = m - 1 - point.first; high = point.first;}
        }
        

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_number;
            if (horizontal) {
                mid_number = matrix[point.first][mid];
            }
            else {
                mid_number = matrix[mid][point.second];
            }
            if (mid_number == target) return true;
            else if (mid_number > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
//简单的查找方法
//on every iteration (during which we do not return true) 
//either row or col is is decremented/incremented exactly once.
//Because row can only be decremented mm times and col can only be incremented nn times 
//before causing the while loop to terminate, the loop cannot run for more than n+mn+m iterations.
// Because all other work is constant, the overall time complexity is linear in the sum of the dimensions of the matrix.
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int row = m - 1, col = 0;
        while (row >= 0 && col < n) {
            int number = matrix[row][col];
            if (number == target) return true;
            if (number > target) row--;
            else if (number < target) col++;
        }
        return false;
    }
};