#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMinMove0110(vector<int> nums) {
        // 0 1 0 1
        // 0 0 1 1 (1)
        // 1 1 0 0 (3)

        //1 1 1 1 0 1 0 1
        //0 0 1 1 1 1 1 1 (4+5=9)
        //1 1 1 1 1 1 0 0 (3)
        int zeroLeft = 0, zeroRight = 0, n = nums.size();
        int leftCount = 0, rightCount = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroLeft += i - leftCount;
                leftCount++;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                zeroRight += (n - rightCount) - i;
                rightCount++;
            }
        }

        return min(zeroLeft, zeroRight);

    }

        

    

};

int main() {
    Solution* ss = new Solution();
    vector<int> nums = {1, 1, 1, 1, 0, 1, 0, 1};
    int pos = ss->findMinMove0110(nums);
    cout << pos << endl;
    return 0;
}