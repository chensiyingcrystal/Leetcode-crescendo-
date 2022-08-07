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

    int findMaxAZ(string s) {
        int ans = 0, countA = 0, countZ = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                countA++;
            }
            else if (s[i] == 'Z') {
                countZ++;
                ans += countA;
            }
        }
        return ans;
    }

    

    

};

int main() {
    Solution* ss = new Solution();
    string s = "01001";
    int pos = ss->findEarliestMonth(nums);
    cout << pos << endl;
    return 0;
}