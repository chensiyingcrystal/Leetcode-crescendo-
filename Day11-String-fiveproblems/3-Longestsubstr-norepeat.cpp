#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

class Solution {
public:
   Solution() {


   }
    int lengthOfLongestSubstring(string s) {
        // 定义方程
        // L(i) 至当前index为i，最长不重复substring的长度
        // S(i) 当前index为i时，不重复substring的长度
        // L(i) = max(L(i - 1), S(i))
        // S(i)按照1递增， if s[i] != s[i - 1], ..., s[c], c为最新断点的index，初始值为0
        //     停止递增，if s[i] = s[i - 1] || ... || s[c], 并且设置最后遇到相等的j+1为最新的断点

        // special case
        int n = s.length();
        if (n <= 1) return n;
        // define =（区分哪些是在循环外对所有i定义的，哪些是每一轮循环需要更新的）
        // 用bool作flag的时候一定要注意每一轮是更新的
        int ans = 1;
        int breakpoint = 0;
        // begin loop through
        for(int i = 1; i < n; i++) {
            // sublength每一轮更新并且写入ans中，i的sublength与之前的没有关系，不需要每个i单独的记忆存储
            int sub_length = 1;
            // 如果i的状态是与离它最近的j有关，应该是逆向！
            for(int j = i - 1; j >= breakpoint; j--) {
                if (s[i] == s[j]) {
                    // breakpoint的发生不是在i，而是在j
                    breakpoint = j + 1;
                    break;
                }
                // sublength的状态不是上一个+1，是递增，或者是i-c+1，其中c为最近的breakpoint点
                sub_length ++;
            }
            ans = max(ans, sub_length);
        }
        return ans;
    }

    // 利用滑动窗口方法将时间复杂度降至o(n):思路与上面是一样的！但是执行方法可以跑一遍就够！
        int lengthOfLongestSubstring(string s) {
            // 为什么这样写可以执行？为什么效率比unordered_map更高？
            vector<int> chars(128);
            int left = 0;
            int right = 0;
            int ans = 0;
            
            while(right < s.length()) {
                chars[s[right]]++;
                while (chars[s[right]] > 1) {
                    chars[s[left]]--;
                    left++;
                }
                ans = max(ans, right - left + 1);
                right++;
            }
            return ans;  
    }
};


int main() {
    return 0;
}