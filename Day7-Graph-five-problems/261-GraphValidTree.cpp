#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    Solution() {

    }

    bool Graphvalidtree(int n, vector<vector<int> >& edges) {
        unordered_map<int, vector<int> > node_map;
        unordered_set<int> visited(n, 0);
        queue<int> q;
        int count = n - 1;
        for(int i = 0; i < edges.size(); i++) {
            node_map[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    count --;
                    for(auto& neighbor : node_map[node]) {
                        if (visited[neighbor]) return false
                        q.push(neighbor);
                        visited[neighbor] = 1;
                    }
                    visited[node] = 1;
                }
            }
        }
        return n == 0;
    }
};

int main() {
    return 0;
}