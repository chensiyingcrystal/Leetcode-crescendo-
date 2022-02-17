#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }

    bool isAnagram(string s, string t) {
        //错误判断的特殊case
        // if (s.empty() || t.empty()) return false;
        // 容易忽略的点： 这种类型的题，对于特殊case记得判断大小，s的size不能小于t的
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s_map, t_map;
        for (char c : s) s_map[c]++;
        for (char c : t) t_map[c]++;

        for (auto& c : s_map) {
            //not using '.count' here
            //count函数直接放回的是一个数值，如果存在，那么返回1，反之0；
            //find返回的是一个iterator， 直接输出iterator是会报错的，要输出的话得取出迭代器的值再输出。 
            if (t_map[c.first] != s_map[c.first]) return false;
        }
        return true;
    }

//space and time optimized edition
        bool isAnagram(string s, string t) {
            if (s.empty() || t.empty()) return false;
            if (s.size() != t.size()) return false;

            //这里用vector int和array的时间空间差别不大
            // int st[26] = {0};
            vector<int> st(26);
            for (char c : s) st[c - 'a']++;
            for (char c : t) st[c - 'a']--;

            for (int i = 0; i < 26; i++) { 
                if (st[i] != 0) return false;
            }
            return true;
        }
};