#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
//这道题直觉感是使用二分，但是如何使用却需要分解问题的能力
//错误思路：想着沿着四周分别进行二分（从左上角汇聚到右下角）但二分的使用前先存为数组（消耗时间on，得不偿失）
//学习技巧：如何按照diag来移动（一层循环控制i就好了，因为此时row和col都为i） + 二分要用index来做！！！
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
//自己的另一种思路，利用左上角点和右下角点的范围进行控制，加速判断

};