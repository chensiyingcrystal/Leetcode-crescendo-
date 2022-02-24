#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//solution: the child with minimum greed factor get smallest cookies first
//问题：想不出思路；只会用暴力解法；代码错误
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //排序是常见的预处理操作，时间复杂度o(nlogn)
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;

        unordered_map<int, int> visited;
        for (auto& x : s) {
            visited[x] = 0;
        }
//问题：不知道如何标记该饼干已被拿走或者不要重新访问，减少时间复杂度
//解决：既然已经排好序了，i和j应该一起移动
        for (auto i : g) {
            for (auto j : s) {
                if (j >= i && visited[j] != 1) {
                    count += 1;
                    //错误原因：用s的元素而不是index表示，s中元素会重复！！
                    //用map或者set时先考虑元素是不是重复
                    visited[j] = 1;
                    //bug：边界条件控制不对，没有考虑如何进入下轮循环
                    break；
                }
            }
        }

        return count;
    }

//正确代码
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                count++;
            }
            j++;
        }
        return count;
    }


//或者代码也可以这样写



};