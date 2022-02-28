#include <unordered_set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    //此题是非常经典的双指针题：本身判断是否是panlindrome就可以用双指针解题
    //这道题展示了双指针在删除元素方面的应用：将指针index作为argument传入进行判定，作为下个函数里面指针的起始
//正确解法：
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        int count = 0;

        while (left <= right) {
            if (s[left] != s[right]) return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            else {
                left++;
                right--;
            }
        }
        return true;  
    }
//精简写法
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
//错误原因：不能遇到不相等就同时移动两个指针，也不能主观认定我移动左边，还是右边
//也不是根据相邻的判断是移动左边还是右边（不是贪心）
    bool validPalindrome(string s) {
        const int n = s.size();
        int left = 0, right = n - 1;
        int count = 0;

        while (left <= right) {
            if (s[left] != s[right]) count++;
            if (count > 1) return false;
            left++;
            right--;
        }
        return true;  
    }
//第一遍的暴力解：超时
    bool validPalindrome(string s) {
        if (isPalindrome(s)) return true;

        for (int i = 0; i < s.size(); i++) {
            string new_s;
            if (i == 0) {
                new_s = s.substr(1, s.size() - 1);
            }            
            else if (i == s.size() - 1) {
                new_s = s.substr(0, s.size() - 1);
            }
            else {
                new_s = s.substr(0, i) + s.substr(i + 1, s.size() - 1 - i);
            }
            
            if (isPalindrome(new_s)) return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        const int n = s.size();

        if (n <= 1) return true;
        if (n == 2) return s[0] == s[1];

        int left = 0, right = n - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};