#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
//自己尝试写的第一种方法：建立两个数组 没写出来 原因：最后得到的结果没有排除左边多余的字符
//解决办法：为什么一定要在找到下一个多的时候滑动，而不是在刚好找到的时候滑动，在发现减少的时候停止滑动
//并且在滑动左边之前记录下最短长度。
//下次遇到类似问题：不要假定一种想法，一定要在那时候开始滑动，想的时候就要同时存在多种假定。
//错误2: 用count计数只能在不重复字母下用，如果允许重复的话，得用unique字母
    string minWindow(string s, string t) {
        const int n = t.size();
        int left = 0, right = 0;
        int count = 0;
        int start = 0, size = INT_MAX;

        unordered_set<char> t_set;
        for (char c : t) {
            t_set.insert(c);
        }

        while (right < s.size()) {
            if (t_set.find(s[right]) != t_set.end()) count++;

            int new_size = right - left + 1;

            while (count >= n) {
                if (new_size < size) {
                    size = new_size;
                    start = left;
                }

                if (t_set.find(s[left]) != t_set.end()) count--;
                left++;
            }

            right++;
        }
        return s.substr(start, size - 1);  
    }    
//改进代码
    string minWindow(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        
        //考虑special case
        if (m < n) return "";
        
        int left = 0, right = 0;
        int count = 0;
        int start = 0, size = INT_MAX;

        //单纯的count数量不能够防止重复字母的出现
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        const int k = need.size();

        while (right < m) {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) count++;
            }
            
            //用unique字母的数量进行计数
            while (count == k) {
                //更新size要放在循环里面，这样排除掉多余字母后也能实时更新
                int new_size = right - left + 1;
                if (new_size < size) {
                    size = new_size;
                    start = left;
                }

                char x = s[left];
                if (need.count(x)) {
                    window[x]--;
                    if (window[x] < need[x]) count--;
                }

                left++;
            }

            right++;
        }
        //有可能出现没有进入循环的情况，所以要有条件返回
        return size == INT_MAX? "" : s.substr(start, size);  
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};