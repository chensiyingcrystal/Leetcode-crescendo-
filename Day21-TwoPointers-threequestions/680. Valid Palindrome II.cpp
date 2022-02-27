#include <unordered_set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    
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