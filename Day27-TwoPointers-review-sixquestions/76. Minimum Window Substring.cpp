#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //restriction, quick decide
        if (t.size() > s.size()) return "";
        //create two hash maps to compare 
        //need to string t, got for string s
        unordered_map<char, int> need;
        unordered_map<char, int> got;
        for (char& c : t) {
            need[c]++;
        }
        //use sliding window to determine minimum window
        int start = 0, size = INT_MAX;
        int left = 0, right = 0;
        int count = 0;
        while (right < s.size()) {
            if (need.count(s[right])) {
                got[s[right]]++;
                if (got[s[right]] == need[s[right]]) {
                    count++;
                }
            }

            while (count == need.size()) {
                if (right - left + 1 < size) {
                    size = right - left + 1;
                    start = left;
                }

                if (need.count(s[left])) {
                    got[s[left]]--;
                    if (got[s[left]] < need[s[left]]) count--;
                }

                left++;
            }

            right++;
        }

        return size == INT_MAX? "" : s.substr(start, size);
    }
        
};