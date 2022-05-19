#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
//more intuitive method: find a "01" and "10" 
//and then expand around it, however the time complexity is o(n2)
    int countBinarySubstrings(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1' || s[i] == '1' && s[i + 1] == '0') {
                helper(s, i, count);
            }
        }
        return count;
    }

    void helper(string s, int i, int& count) {
        int n = s.length();
        int left = i, right = i + 1;
        char pre_left = s[left], pre_right = s[right];
        while (left >= 0 && right < n && s[left] == pre_left && s[right] == pre_right) {
            count++;
            left--;
            right++;
        }
        return;
    }

};