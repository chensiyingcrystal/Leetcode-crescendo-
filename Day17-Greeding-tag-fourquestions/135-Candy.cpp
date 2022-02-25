#include <unordered_map>
#include <bits/stdc++.h>
#include <numeric>

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

        // int sum_cookies = 0;
        // for (auto& cookie : cookies) {
        //     sum_cookies += cookie;
        // }
        //快速求和
        return accumulate(cookies.begin(), cookies.end(), 0);
    }

//错误解法：只用一遍循环
//错误原因：如果是递增序列这样可以，但如果是递减序列，当前值确定后，下一个值有可能也增加，发生改变
//这样还是要回过头来重新看，因此要从前向后遍历，再从后向前遍历，保证之前在后置位的这回在前置位
//每次看哪个方向呢？
//正确：从左扫向左看，从右扫向右看，只修改自己的值，即每次只关注自己是否高了而candy少了
//错误:第一遍向左向右看，进行初步递增，第二遍检查，看是否存在自己高于别人但糖果数字低的
//错误原因：这样就达不到最少糖果的要求了，如果出现peak两边是valley的情况，peak将会多增加一次

    
};