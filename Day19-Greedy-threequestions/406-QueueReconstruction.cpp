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

//数据结构知识：动态数组底层是用普通数组实现的
//动态数组有两个大小，一个是size，就是我们调用size函数得到的值，一个是capacity，是不暴露在外的
//当插入元素后超过capacity时，会自动开辟一片两倍于原先的内存
//将原有元素一一拷贝过来后，再释放原数组内存
//因此上面的方法虽然用动态数组实现表面复杂度是o(n2)，但实际上远远不止，应该是o(n2+t*n),其中t是全量拷贝的次数
//那如果提前对动态数组定义好容量空间，再用insert，insert还是同样的实现方法
//那如果提前定义好空间，而不用insert呢？手动模拟插入操作呢？实现的效率还是没有链表高效


//用链表实现，可以极大地缩短时间，虽然表面上时间复杂度还是o(nlogn + n2) (advance需要o(n))
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>&b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            else return a[0] > b[0];
        });

        list<vector<int>> q;
        for (int i = 0; i < people.size(); i++) {
            list<vector<int>>::iterator it = q.begin();
            advance(it, people[i][1]);
            //list唯一费时的是寻找插入的位置，这一步也可以用while循环实现
            // int position = people[i][1];
            // while (position--) {
            //     it++;
            // }
            q.insert(it, people[i]);
        }
        //如何将链表转换为动态数组
        return vector<vector<int>> (q.begin(), q.end());
    }
};