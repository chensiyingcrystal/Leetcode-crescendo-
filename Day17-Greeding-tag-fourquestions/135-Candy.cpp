#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//问题：思路错误，只考虑了每个节点和左边的情况，没有考虑右边的(只考虑了数列递增的情况，没有考虑decreasing order)
//正确思路：从左遍历一边，从右遍历一遍
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> cookies(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cookies[i] = cookies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            //后面的条件非常重要
            if (ratings[i] > ratings[i + 1] && cookies[i] <= cookies[i + 1]) {
                cookies[i] = cookies[i + 1] + 1;
            }
        }

        int sum_cookies = 0;
        for (auto& cookie : cookies) {
            sum_cookies += cookie;
        }

        return sum_cookies;
    }

    // int candy(vector<int>& ratings) {
    //     if (ratings.empty()) return 0;
    //     //find minimum value, record its index
    //     int min_rating = INT_MAX, k;
    //     for (int i = 0; i < ratings.size(); i++) {
    //         if (ratings[i] < min_rating) {
    //             k = i;
    //             min_rating = ratings[i];
    //         }
    //     }

    //     //from index k to right, counting
    //     int cookies = 1, sum_cookies = 1;
    //     for (int i = k + 1; i < ratings.size(); i++) {
    //         if (ratings[i] > ratings[k]) { 
    //             cookies++;
    //         }
    //         else cookies = 1;
    //         sum_cookies += cookies;
    //         k = i;
    //     }

    //     //from 0 to index k, counting
    //     int cookies = 1;
    //     for (int i = k - 1; i >= 0; i--) {
    //         if (ratings[i] > ratings[k]) {
    //             cookies++;
    //         }
    //         else cookies = 1;
    //         sum_cookies += cookies;
    //         k = i;
    //     }

    //     return sum_cookies;
    // }
 
};