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
        return countA >= countZ ? ans + countA : ans + countZ;
    }

    

    

};

int main() {
    Solution* ss = new Solution();
    string s = "BAZAZ";
    int pos = ss->findMaxAZ(s);
    cout << pos << endl;
    return 0;
}