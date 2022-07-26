#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";

        int left = 0, right = 0;
        unordered_map<char, int> freq_t;
        unordered_map<char, int> freq_s; //record each character's frequency
        int count = 0; // record the number of valid character
        for (char& c : t) {
            freq_t[c]++;
        }
        int need = freq_t.size();
        
        int minLength = INT_MAX, start = 0;

        while (right < m) {
            char c = s[right];
            freq_s[c]++;
            if (freq_t.count(c) && freq_t[c] == freq_s[c]) count++;

            while (count == need) {
                if (right - left + 1 < minLength) {
                    start = left;
                    minLength = right - left + 1;
                }

                char c1 = s[left];
                if (freq_t.count(c1) && freq_s[c1] == freq_s[c1]) count--;
                freq_s[c1]--;
                left++;
            }

            right++;
    }

        return minLength == INT_MAX? "" : s.substr(start, minLength);
    }
//用vector<int>的优化
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) return "";

        int left = 0, right = 0;
        vector<int> freq_t(128, 0);
        vector<int> freq_s(128, 0); //record each character's frequency
        int count = 0, need = 0; // record the number of valid character
        for (char& c : t) {
            if (freq_t[c] == 0) need++;
            freq_t[c]++;
        }
        int minLength = INT_MAX, start = 0;

        while (right < m) {
            char c = s[right];
            freq_s[c]++;
            if (freq_t[c] != 0 && freq_t[c] == freq_s[c]) count++;

            while (count == need) {
                if (right - left + 1 < minLength) {
                    start = left;
                    minLength = right - left + 1;
                }

                char c1 = s[left];
                if (freq_t[c1] != 0 && freq_s[c1] == freq_t[c1]) count--;
                freq_s[c1]--;
                left++;
            }

            right++;
    }

        return minLength == INT_MAX? "" : s.substr(start, minLength);
    }
};