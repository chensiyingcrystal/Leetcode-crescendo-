#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
//方法二： 推荐，学习写法！！卡壳的原因是不是j = i+1， 而是在下一次backtrack的时候传比自己大的值！！！
//极大降低时间复杂度
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> temp;
        int first = 1;
        backtrack(n, k, first, temp, ans);
        return ans;
    }

    void backtrack(int& n, int& k, int first, vector<int>& temp, vector<vector<int> >& ans) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = first; i <= n; i++) {
            temp.push_back(i);
            backtrack(n, k, i + 1, temp, ans);
            temp.pop_back();
        }
    }
//方法一： 自己写的不推荐，直接暴力穷举+筛选index
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> temp;
        backtrack(n, k, temp, ans);
        return ans;
    }

    void backtrack(int& n, int& k, vector<int>& temp, vector<vector<int> >& ans) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            //temp的最后元素索引要注意加入不为空的条件
            if (!temp.empty() && i <= temp.back()) continue;
            temp.push_back(i);
            backtrack(n, k, temp, ans);
            temp.pop_back();
        }
    }
};
