#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    Solution() {


    }
//easy solution: reverse and compare, little trick: sift all alnum
  bool isPalindrome(string s) {
    string filtered_string, reversed_string;

//filtering
    for (auto ch : s) {
    //use isalnum to determine if it's an Alphanumeric character
      if (isalnum(ch))
        filtered_string += tolower(ch);
    }

//reversing
    reversed_string.resize(filtered_string.size());
    reverse_copy(filtered_string.begin(), filtered_string.end(),
                 reversed_string.begin());

//comparing
    return filtered_string == reversed_string;
  }

//常规做法（自己写的）
    bool isPalindrome(string s) {
        string t;
        for (char c : s) {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || 
                (c >= 'A' && c <= 'Z')) {
                    //加32 而不是加‘a’，加‘a’是转换为int
                    if (c >= 'A' && c <= 'Z') c += 32; 
                    t += c;
                }
        }
        
        if (t.empty()) return true;
        const int n = t.size();
        for (int i = 0; i < n/2; i++) {
            if (t[i] != t[n - 1 - i]) return false;
        }
        return true;
    }

};