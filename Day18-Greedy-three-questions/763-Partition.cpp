#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }

    vector<int> partitionLabels(string s) {
        int last_index[26];
        //bug:length()
        const int n = s.length();
        //最巧妙的点在于：记录最后到达的位置，利用贪心的思想对最后的index进行更新，实质上还是区间问题
        //贪心：需要用到极值思维，就是在当前条件下，如何做到让结果最大化或者最小化？
        //局部最优 -> 全局最优
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        } 
        vector<int> result;    
        int start = 0;
        while (start <= n - 1) {
            int anchor = last_index[s[start] - 'a'];
            for (int i = start; i <= anchor; i++) {
                anchor = max(anchor, last_index[s[i] - 'a']);
            }
            int length = anchor - start + 1;
            result.push_back(length);
            start = anchor + 1;
        }
        return result;
    }

//学习：同样的代码可以用一遍for循环实现
    vector<int> partitionLabels(string s) {
        int last_index[26];
        const int n = s.length();
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        } 
        vector<int> result;    
        int anchor = last_index[s[0] - 'a'], start = 0;
        //学习这样的写法：for循环一遍遍历，中到了某个条件就会触发
        //思考：触发前对于每个i需要完成的操作是什么？触发中的操作是什么？
        //既然是个循环，那么需要设置哪些变量在每轮更新？什么变量是触发后更新？
        //for循环中写if语句触发是经典写法，这样写与while循环是一致的，只是在while循环中这样的触发中操作变成了递增
        for (int i = 0; i < n; i++) {
            anchor = max(anchor, last_index[s[i] - 'a']);
            if (i == anchor) {
                result.push_back(anchor - start + 1);
                start = anchor + 1;
                //这里不需要对anchor进行更新了，到了下一步会自动更新，只要保证start的位置就好
                //bug：这里如果要写这句，要对start进行限定，否则会溢出
                // anchor = last_index[s[start] - 'a'];
            }
        }
        return result;
    }
};