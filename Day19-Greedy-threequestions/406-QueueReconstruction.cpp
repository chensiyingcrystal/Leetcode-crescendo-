#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//这里贪心的核心是：
//最短的元素前面排了几个，自己就是下一个，因此最短元素的位置每次都是确定的
//那么就要想办法让每次进行操作的元素都是当前最短的，而不是按照从小到大排，只有第一次取出的才是最短的
//错误原因：不要相对没有排的元素是最短的，而是要相对已经排序的是最短的
//那么就应该按照从大到小排，正方向想不通的时候，反方向想一想
//数据结构：vector的insert操作，每次time是o(k)，k是每次插入时list里面已有的元素
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>&a, vector<int>&b) {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] > b[0];
        });

        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};