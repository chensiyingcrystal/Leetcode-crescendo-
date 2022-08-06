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

    long long find010101Sequence(string s) {
        int n = s.length();
        long long prev0 = 0, prev1 = 0;
        long long prev10 = 0, prev01 = 0;
        long long prev010 = 0, prev101 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                prev0++;
                prev10 += prev1;
                prev010 += prev01;
            }
            else {
                prev1++;
                prev01 += prev0;
                prev101 += prev10;
            }
        }
        return prev010 + prev101;
    }

};

int main() {
    Solution* ss = new Solution();
    string s = "01001";
    int pos = ss->findEarliestMonth(nums);
    cout << pos << endl;
    return 0;
}