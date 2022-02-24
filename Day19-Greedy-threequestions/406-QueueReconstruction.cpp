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
//进入这个思路的核心：首先，直觉觉得这个序列肯定需要预处理排序，那么按照第一个元素从小到大是怎样的？
//类似dp，先想想只有两个元素是分几种情况，每种怎么排，再加入一种怎么排
//如果从小到大想不通，就及时换种顺序想！！！
//发现最短元素确定位置的规律：每次排序都会受到前面的干扰，但只有一个元素不会干扰别人，那就是最短元素
//可以先试着比划，但时间不宜过长，因为贪心肯定是有原理的，不要在用实例模拟上花太多时间
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