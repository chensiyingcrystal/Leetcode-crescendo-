#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findPasswordStrength(string s) {
        int n = s.length(), ans = 0;
        bool yuan = false, fu = false;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) yuan = true;
            else fu = true;
            if (yuan && fu) {
                ans++;
                yuan = false;
                fu = false;
            }
        }
        return ans;
    }

    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }


};

int main() {
    Solution* ss = new Solution();
    string s = "thisisbeautiful";
    int pos = ss->findPasswordStrength(s);
    cout << pos << endl;
    return 0;
}