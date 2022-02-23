#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }

    vector<int> partitionLabels(string s) {
        int last_index[26];
        const int n = s.length;
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        } 
        vector<int> result;    
        int start = 0;
        while (start <= n - 1) {
            int anchor = last_index[s[start] - 'a'];
            for (int i = start; i <= anchor; i++) {
                anchor = max(anchor, last_index[s[i] - 'a']);
            }
            int length = anchor - start + 1;
            result.push_back(length);
            start = anchor + 1;
        }
        return result;
    }
    
//学习：同样的代码可以用一遍for循环实现
    vector<int> partitionLabels(string s) {
        int last_index[26];
        const int n = s.length;
        for (int i = 0; i < n; i++) {
            last_index[s[i] - 'a'] = i;
        } 
        vector<int> result;    
        int start = 0;
        while (start <= n - 1) {
            int anchor = last_index[s[start] - 'a'];
            for (int i = start; i <= anchor; i++) {
                anchor = max(anchor, last_index[s[i] - 'a']);
            }
            int length = anchor - start + 1;
            result.push_back(length);
            start = anchor + 1;
        }
        return result;
    }
};