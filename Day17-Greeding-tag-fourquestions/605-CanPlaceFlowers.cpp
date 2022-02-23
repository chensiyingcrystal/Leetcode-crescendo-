#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        const int m = flowerbed.size();
        if (m == 1) return n == 1 && flowerbed[0] != 1;
        for (int i = 0; i < m; i++) {
            //条件本身，邻居，边界条件
            if ((i == 0 && flowerbed[i] != 1 && flowerbed[1] != 1) || (i == m - 1 && flowerbed[i] != 1 && flowerbed[i - 1] != 1) || 
                (i != 0 && i != m - 1 && flowerbed[i] != 1 && flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1)) {
                flowerbed[i] = 1;
                n--;
                //重要判别条件
                if (n == 0) return true;
            }
        }
        return false; 
    }
};