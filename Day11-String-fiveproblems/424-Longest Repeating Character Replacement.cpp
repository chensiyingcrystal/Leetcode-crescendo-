#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    Solution() {


    }
//时间复杂度为不同字符的数量（最大26） * n（每次滑动窗口的复杂度为字符串长度）
//26是常数，所以时间复杂度是o(n)
    int characterReplacement(string s, int k) {
        //标记字符，不进行重复算
        unordered_set<char> visited;
        //针对每一个字符，以转成该字符为目标，进行从左至右的滑动窗口，记录能连成的最长字符，取最大
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (visited.find(s[i]) == visited.end()) {
                int ans_i = slidingwindow(s, k, s[i]);
                ans = max(ans, ans_i);
                visited.insert(s[i]);
            }
        }
        return ans;
    }

    int slidingwindow(string s, int k, char ch) {
        //初始左窗口和右窗口，右边的以达到字符串最右为终点进行滑动，以k次数不够了触发左边窗口滑动
        //每次right循环中记录的是以当前字符为末尾的能满足要求的（k）最长字符，对结果进行实时更新
        int result = 0;
        int count = 0;
        int right = 0, left = 0;
        while (right < s.length()) {
            if (s[right] != ch) count++;
            while (count > k) {
                if (s[left] != ch) count --;
                left++;
            }
            result = max(result, right - left + 1);
            right ++;
        }
        return result;
    }
};