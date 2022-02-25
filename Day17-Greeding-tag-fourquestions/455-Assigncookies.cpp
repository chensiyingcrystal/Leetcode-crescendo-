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


//错误代码：
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;
        //bug2: 这里写for循环要格外注意，将g写在外围是错误的，这样会要产生两层循环
        //而实际上一层循环就应该做到
        for (int i = 0; i < g.size(); i++) {
            //bug1:要将对索引的限制写在引用索引之前，这样可以引起及时的短路，不至于去引用s[j+1]
            if (j < s.size() && g[i] <= s[j]) {
                j++;
                count++;
            }
        }
        return count;
    }

//正确代码
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < g.size() && s[i] >= g[j]) {
                j++;
                count++;
            }
        }
        return count;
    }
//更进一步的做法是，j到了哪个小孩的位置，它之前的小孩肯定都分了才轮到他，因此j的位置可以指示number
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < g.size() && s[i] >= g[j]) {
                j++;
            }
        }
        //本来应该返回j+1，但是j在循环结束后都会自增1，所以最后小孩数量应该就是j本身
        return j;
    }
};