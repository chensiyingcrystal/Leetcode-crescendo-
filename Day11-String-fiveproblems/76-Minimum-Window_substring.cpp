#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Solution {
public:
    Solution() {


    }
//solution1: sliding window: use two maps: need and window and one counter
    string minWindow(string s, string t) {
        //special case
        if (s.length() < t.length()) return "";
        if (s.empty() || t.empty()) return "";
        
        //initialize need map
        unordered_map<char, int> need, window;
        //bug点 应该是++ 而不是等于1 因为会有重复字母出现
        for (char c : t) need[c]++;

        //two pointers, one counter, save result
        // bug点： 注意c++中不能这样赋值！！类型可以省略，但是值不可以
        // int left, right = 0;
        int left = 0, right = 0;
        int valid = 0;
        int minStart = 0, minLen = INT_MAX;

        //begin sliding
        while (right < s.length()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (need[s[right]] == window[s[right]]) valid++;
            }
            
            //bug点： valid应该是等于need的size，因为会有重复字母出现，valid的含义是unique字母全部出现才触发
            while (valid == need.size()) {
                //record result
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                if (need.count(s[left])) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]]) valid--;
                }

                left++;
            }

            right++;
        }
        return minLen == INT_MAX? "" : s.substr(minStart, minLen);
    }

//optimized edition: one vector, one counter
    string minWindow(string s, string t) {
        //use ASCII value as character's index,vector uses less memory
        //should use 128 here, unless it will overflow
        vector<int> hist(128, 0);
        for (char c : t) hist[c]++;
        
        int remaining = t.length();
        int left = 0, right = 0, minStart = 0, minLen = INT_MAX;
        while (right < s.length()){
            // decrease runtime
            if (minLen == t.size())
                break;
            //通过控制值的增减 判断有没有触发
            if (--hist[s[right++]] >= 0) remaining--;
            while (remaining == 0){
                if (right - left < minLen){
                    minLen = right - left;
                    minStart = left;
                }
                if (++hist[s[left++]] > 0) remaining++;
            }
        }   
        return minLen != INT_MAX ? s.substr(minStart, minLen) : "";
    }
};