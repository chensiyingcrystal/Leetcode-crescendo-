#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int maxArea(vector<int>& height) {
        const int n = height.size();
        int j = 0, k = n - 1;
        int max_area = 0;
        while (j < k) {
            int area = min(height[j], height[k]) * (k - j);
            if (area > max_area) {
                max_area = area;
            }
            if (height[j] > height[k]) --k;
            else ++j;
        }
        return max_area;
    }

};


int main() {
    vector<int> nums;
    nums.push_back(1);  
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(3);
    nums.push_back(7);
    Solution* ss = new Solution();
    int result = ss->maxArea(nums);
    cout << result;
}