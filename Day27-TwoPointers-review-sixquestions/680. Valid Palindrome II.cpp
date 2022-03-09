#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        //special case: s.length() == 1
        if (s.length() <= 2) return true;
        //two pointers: see if s[left] == s[right]
        int left = 0, right = s.length() - 1;
        //奇数偶数情况下，left与right交汇处进入循环对结果没有影响
        while (left <= right) {
            if (s[left] != s[right]) {
                //直接return，因为只有一次机会，不需要计数器
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }   
};