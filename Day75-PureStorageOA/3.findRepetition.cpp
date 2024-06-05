#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int FindRepetition(string s, string l) {
        int ns = s.length(), nl = l.length();
        vector<int> dp(nl + 1, 0);
        int res = 0;

        for (int i = 1; i < nl + 1; i++) {
            if ((i - 1 - ns) >= 0 && l.substr(i - 1 - ns, ns) == s) {
                dp[i] = dp[i - ns] + 1;
            } 
            res = max(res, dp[i]);
        }

        return res;
    }



};

int main() {
    Solution* ss = new Solution();
    string s = "AB", l = "ABCABCEEABABDSFAB";
    int ans = ss->FindRepetition(s, l);
    cout << ans << endl;
    

    return 0;


}