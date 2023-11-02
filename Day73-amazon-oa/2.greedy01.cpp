#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMinEfficiency(string s) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '?') {
                s[i] = s[i - 1];
            } else if (s[i] == '0') {
                if (s[i - 1] == '1') count++;
            } else if (s[i] == '1') {
                if (s[i - 1] == '0') count++;
            }
        }
        return count;
        
    }



};

int main() {
    Solution* ss = new Solution();
    string s = "??011??0";
    int ans = ss->findMinEfficiency(s);
    cout << ans << endl;

    return 0;


}