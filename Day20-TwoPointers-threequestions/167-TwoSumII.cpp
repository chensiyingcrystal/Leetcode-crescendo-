#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
    //用双指针解这道题的优点：space o（1）
    //前提：序列是排好序的
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int k = numbers.size();
        vector<int> result;
        int i = 0, j = k - 1;
        while (i < k - 1 && j > 0 && i < j) {
            int ans = numbers[i] + numbers[j];
            if (ans == target) {
                //code optimization
                return {i + 1, j + 1};
                // result.push_back(i + 1);
                // result.push_back(j + 1);
                // i++;
                // j--;
            }
            else if (ans > target) {
                j--;
            }
            else {
                i++;
            }
        }
        //在if语句中return的，要保证函数在外面也有return值
        return {-1, -1};
        // return result;
    }  
    
//更简洁的写法
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) break;
            if (sum > target) r--;
            else ++l;
        }
        return {l + 1, r + 1};
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         )
};