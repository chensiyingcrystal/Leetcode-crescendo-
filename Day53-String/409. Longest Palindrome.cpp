#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public: 
//primary edition
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }

        int sum = 0;
        bool flag = true;
        for (auto& pair : map) {
            if (pair.second % 2 == 0) {
                sum += pair.second;
            }
            if (pair.second % 2 != 0) {
                sum += pair.second - 1;
                flag = false;
            }
        }
        return flag? sum : sum + 1;
    }
//optimized edition
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }

        int sum = 0;
        bool flag = true;
        for (auto& pair : map) {
            //optimize here
            sum += pair.second / 2 * 2;
            if (pair.second % 2 != 0) {
                flag = false;
            }
        }
        return flag? sum : sum + 1;
    }
};