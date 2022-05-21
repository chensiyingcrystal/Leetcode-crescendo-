#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public: 
//暴力解法
    int strStr(string haystack, string needle) {
        //special case: empty string
        if (needle.empty() || haystack.empty()) return 0;
        int len_h = haystack.length(), len_n = needle.length();
        if (len_n > len_h) return -1;

        int first = -1;
        for (int i = 0; i < len_h; i++) {
            int ph = i, pn = 0;
            bool flag = true;
            while (ph < len_h && pn < len_n) {
                if (haystack[ph] != needle[pn]) {
                    flag = false;
                    break;
                }
                else {
                    ph++;
                    pn++;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
//暴力解法的代码优化一
    int strStr(string haystack, string needle) {
        int len_h = haystack.length(), len_n = needle.length();
        for (int i = 0; i + len_n - 1 < len_h; i++) {
            bool flag = true;
            for (int j = 0; j < len_n; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            //i not changed since we use j to increment i
            if (flag) return i;
        }
        return -1;
    }
//暴力解法的代码优化二
    int strStr(string haystack, string needle) {
        int len_h = haystack.length(), len_n = needle.length();
        for (int i = 0; i + len_n <= len_h; i++) {
            int ph = i, pn = 0;
            while (pn < len_n && haystack[ph] == needle[pn]) {
                ph++;
                pn++;
            }
            if (pn == len_n) return i;
        }
        return -1;
    }
//高级算法：KMP
};