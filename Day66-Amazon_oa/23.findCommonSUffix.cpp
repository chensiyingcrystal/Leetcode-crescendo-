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

    vector<int> findCommonSuffix(string s) {
        int n = s.length();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int common = 0, j = 0, start = i; 
            while (start < n) {
                if (s[start++] == s[j++]) {
                    common++;
                }
                else break;
            }
            ans.push_back(common);
        }
        return ans;
    }


};

int main() {
    Solution* ss = new Solution();
    string s = "abcabcd";
    vector<int> pos = ss->findCommonSuffix(s);
    for (auto& num : pos) {
        cout << num << endl;
    }
    return 0;
}