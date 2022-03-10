#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
//要学会将矩阵转换成图论
    int findCircleNum(vector<vector<int> >& isConnected) {
        //首先在循环外声明染色的计数器
        int n = isConnected.size(), count = 0;
        //建立visited的标记，一共n个node，所以建立n个标记就可以了
        vector<int> visited(n);
        //开始循环
        for (int i = 0; i < n; i++) {
            //写条件：在这里只有有没有访问过
            if (!visited[i]) {
                //传参数：原矩阵，index，访问标记
                dfs(isConnected, i, visited);
                //每完成一次深搜，count数目更新1
                count++;
            }
        }
        return count;
    }
//dfs的函数两种写法，第一种是下面的写法，即满足合法条件才开始展开对邻居的搜索
//第二种就是不管三七二十一就开展对邻居的搜索，在函数最前方写下弹回的条件
//从这题的运行时间测试可以看出，数据量如果很大的话，第一种方式有剪枝的话，运行时间快很多
    void dfs(vector<vector<int> >& isConnected, int i, vector<int>& visited) {
        //弹回的条件就是：已标记过
        //这个条件也没有必要写，因为下面已经判断过了，第一次进入的时候也判断过了
        // if (visited[i]) return;

        //enter into this node: first, mark it as visited
        visited[i] = 1;
        //visit its neighbors, if it has
        const int n = isConnected.size();
        //重大bug：理解for loop的执行！！！如果在初始条件就写上i ！= j，那么对于i = 0 的情况而言
        //第一次判断条件不对，根本就不会进入循环！！注意条件是控制进入循环的，如果根本进不了，也就不会递增！！
        for (int j = 0; j < n; j++) {
            //这里的i！=j的条件没有必要，但是判断visit与否，是一种剪枝操作，可以减少运行时间
            if (visited[j] != 1 && isConnected[i][j]) {
                dfs(isConnected, j, visited);
            }
        }
    }
};