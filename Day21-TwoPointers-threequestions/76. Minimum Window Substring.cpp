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
        
        if (m < n) return "";
        
        int left = 0, right = 0;
        int count = 0;
        int start = 0, size = INT_MAX;

        unordered_set<char> t_set;
        for (char c : t) {
            t_set.insert(c);
        }

        while (right < m) {
            if (t_set.find(s[right]) != t_set.end()) count++;

            while (count >= n) {
                int new_size = right - left + 1;
                if (new_size < size) {
                    size = new_size;
                    start = left;
                }

                if (t_set.find(s[left]) != t_set.end()) count--;
                left++;
            }

            right++;
        }
        return size == INT_MAX? "" : s.substr(start, size);  
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};