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
//discussion: https://leetcode.com/discuss/interview-question/2794537
    int getMaxNetVulnerability(vector<vector<int> >& vulnerability) {
        int n = vulnerability.size(), m = vulnerability[0].size();
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxVal = max(maxVal, vulnerability[i][j]);
            }
        }
        //use binary search to find the target value
        int left = 1, right = maxVal;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canGetNetVulnerability(vulnerability, m, n, mid)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
        
    }

    bool canGetNetVulnerability(vector<vector<int> >& vulnerabilities, int& m, int& n, int val) {
        bool foundTwo = false;
        vector<int> rows(n, 0);
        for (int j = 0; j < m; j++) {
            bool foundVal = false;
            for (int i = 0; i < n; i++) {
                if (vulnerabilities[i][j] >= val) {
                    foundVal = true;
                    rows[i]++;
                    if (rows[i] > 1) foundTwo = true;
                }
            }
            if (!foundVal) return false;
        }
        return foundTwo;
    }




    

};

int main() {
    Solution* ss = new Solution();
    vector<vector<int> > v;
    v.push_back({1, 3, 1});
    v.push_back({3, 1, 1});
    v.push_back({1, 2, 2});
    v.push_back({1, 1, 1});
    int ans = ss->getMaxNetVulnerability(v);

    cout << ans << endl;
    return 0;


}