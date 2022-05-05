#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        pair<int, int> left(0, 0), right(m - 1, n - 1);
        while (left.first <= right.first && left.second <= right.second) {
            int low = matrix[left.first][left.second];
            int high = matrix[right.first][right.second];
            if (target > high || target < low) return false;
            
            vector<int> search1;
            vector<int> search2;
            for (int i = left.first, j = left.second; j <= right.second; j++) {
                search1.push_back(matrix[i][j]);
            }
            for (int i = left.first + 1, j = right.second; i <= right.first; i++) {
                search1.push_back(matrix[i][j]);
            }

            for (int j = left.second, i = left.first; i <= right.first; i++) {
                search2.push_back(matrix[i][j]);
            }
            for (int i = right.first, j = left.second + 1; j <= right.second; j++) {
                search2.push_back(matrix[i][j]);
            }

            bool ans = binarySearch(search1, target) || binarySearch(search2, target);
            if (ans) return true;
            left.first++;
            left.second++;
            right.first--;
            right.second--;
        }
        return false;
    }

    bool binarySearch(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false; 
    }
};