#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort two in increasing order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        //record the result
        int number = 0;
        
        //loop through two to assign cookies: assign smallest cookie to the children with less greed factor
        int i = 0, j = 0; 
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                number += 1;
                j++;
                i++;
            }
            else {
                j++;
            }
        }
        
        return number;
    }
};