#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        unordered_map<int, vector<int> > min_heights;
        for (int i = 0; i < n; i++) {
            min_heights[dfs(i, n, edges)].push_back(i);
        }

        int min_height = INT_MAX;
        for (pair<int, vector<int> > p : min_heights) {
            min_height = min(p.first, min_height);
        }
        return min_heights[min_height]; 
    }

    int dfs(int i, int n, vector<vector<int> >& edges) {
        if ()


    }

};