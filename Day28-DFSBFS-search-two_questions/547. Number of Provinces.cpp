#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int findCircleNum(vector<vector<int> >& isConnected) {
        vector<vector<int> > visited(isConnected.size(), vector<int>(isConnected[0].size()));
        int number = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1 && visited[i][j] == 0) {
                    dfs(isConnected, i, j, visited);
                    number++;
                } 
            }
        }
        return number;
    }

    void dfs(vector<vector<int> >& isConnected, int i, int j, vector<vector<int> >& visited) {
        if (i < 0 || i >= isConnected.size() || j < 0 || j >= isConnected[0].size()) return;
        if (isConnected[i][j] == 0 || visited[i][j] == 1) return;

        visited[i][j] = 1;
        dfs(isConnected, i + 1, j, visited);
        dfs(isConnected, i - 1, j, visited);
        dfs(isConnected, i, j + 1, visited);
        dfs(isConnected, i, j - 1, visited);
    }
};