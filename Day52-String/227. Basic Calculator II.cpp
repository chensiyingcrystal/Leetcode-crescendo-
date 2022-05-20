#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
//正确的解法：stack
    int calculate(string s) {
        
    }
//错误的解法：分治
    int calculate(string s) {
        int left = 0, right = s.length() - 1;
        return helper(s, left, right);
    }

    int helper(string s, int left, int right) {
        int m = category(s, left, right);
        if (m == 0) {
            while (left <= right && (s[left] == ' ' || s[right] == ' ')) {
                if (s[left] == ' ') left++;
                if (s[right] == ' ') right--;
            }
            return stoi(s.substr(left, right - left + 1));
        }

        if (m == 1) {
            return flat_calculator(s, left, right);
        }

        if (m == 2) {
            return mixed_calculator(s, left, right);
        }

        return 0;
    }

    int flat_calculator(string s, int left, int right) {
        for (int i = right; i >= left; i--) {
            if (s[i] == '+') {
                return helper(s, left, i - 1) + helper(s, i + 1, right);
            }
            if (s[i] == '-') {
                return helper(s, left, i - 1) - helper(s, i + 1, right);
            }
            if (s[i] == '*') {
                return helper(s, left, i - 1) * helper(s, i + 1, right);
            }
            if (s[i] == '/') {
                return helper(s, left, i - 1) / helper(s, i + 1, right);
            }
        }
        return 0;
    }

    int mixed_calculator(string s, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (s[i] == '+') {
                return helper(s, left, i - 1) + helper(s, i + 1, right);
            }
        }
        for (int i = left; i <= right; i++) {
            if (s[i] == '-') {
                return helper(s, left, i - 1) - helper(s, i + 1, right);
            }
        }

        for (int i = left; i <= right; i++) {
            if (s[i] == '*') {
                return helper(s, left, i - 1) * helper(s, i + 1, right);
            }
        }

        for (int i = left; i <= right; i++) {
            if (s[i] == '/') {
                return helper(s, left, i - 1) / helper(s, i + 1, right);
            }
        }
        return 0;
    }

    int category(string s, int left, int right) {
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+') flag1 = true;
            if (s[i] == '-') flag2 = true;
            if (s[i] == '*') flag3 = true;
            if (s[i] == '/') flag4 = true;
        }
        if (flag1 && flag2 || flag3 && flag4) return 1;
        if (!flag1 && !flag2 && !flag3 && !flag4) return 0;
        else return 2;
    }
    
            

};

int main() {
    Solution* ss = &Solution();
    string s = "3+2*2";
    int ans = ss->calculate(s);
    cout << ans << endl;
    return 0;
}