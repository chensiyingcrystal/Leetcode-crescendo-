#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }

//1. Observe + traverse by column
//For column_i, the rain it can trap:
//r[i] = min(max(h[0~i]), max(h[i~n-1])) - h[i]

//Converting to prefix max
//空间换时间，记忆化
//leftMax, rightMax
//leftMax[i] = max(leftMax[i-1], h[i]), i: 0 ---> n-1, leftMax[0] = h[0]
//rightMax[i] = max(rightMax[i+1], h[i]), i: n-1 ---> 0, rightMax[n-1] = h[n-1]
//r[i] = min(leftMax[i], rightMax[i]) - h[i]
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        vector<int> leftMax(n);
        //count prefix leftMax for each column
        for (int i = 0; i < n; i++) {
            leftMax[i] = i == 0? height[0] : max(leftMax[i - 1], height[i]);
        }
        
        vector<int> rightMax(n);
        //count suffix rightMax for each column
        for (int i = n -1 ; i >= 0; i--) {
            rightMax[i] = i == n - 1? height[n - 1] : max(rightMax[i + 1], height[i]);
        }
        
        
        //for each column i, the water it can trap is r[i] = min(leftMax[i], rightMax[i]) - h[i]
        for (int i = 0; i < n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return sum;

    }
//use one for loop for calculating r[i] and leftMax, which also saves o(n) space for leftMAx
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        int leftMax = 0;
        
        vector<int> rightMax(n);
        //count suffix rightMax for each column
        for (int i = n -1 ; i >= 0; i--) {
            rightMax[i] = i == n - 1? height[n - 1] : max(rightMax[i + 1], height[i]);
        }
        
        //for each column i, the water it can trap is r[i] = min(leftMax[i], rightMax[i]) - h[i]
        for (int i = 0; i < n; i++) {
            leftMax = i == 0? height[0] : max(leftMax, height[i]);
            sum += min(leftMax, rightMax[i]) - height[i];
        }
        
        return sum;

    }
//two pointers
    int trap(vector<int>& height) {
        int h = 0, ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                h = max(h, height[l]);
                ans += h - height[l];
                l++;
            }
            else {
                h = max(h, height[r]);
                ans += h - height[r];
                r--;
            }
        }
        return ans;
    }
//huahua
//经验（盛最多雨水的容器）
//原理：短板，安心移动一个指针，比如移动l的时候，不管r有咩有达到最大值，都不影响l，所以可以安心移动l指针
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_l = height[l], max_r = height[r];
        int ans = 0;
        while (l < r) {
            if (max_l < max_r) {
                ans += max_l - height[l];
                max_l = max(max_l, height[++l]);
            }
            else {
                ans += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return ans;
    }

    
};