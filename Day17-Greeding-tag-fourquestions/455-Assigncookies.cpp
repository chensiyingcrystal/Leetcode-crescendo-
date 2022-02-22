#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//solution: the child with minimum greed factor get smallest cookies first
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        unordered_map<int, int> visited;
        for (auto& x : s) {
            visited[x] = 0;
        }



        

        
    }
 
};