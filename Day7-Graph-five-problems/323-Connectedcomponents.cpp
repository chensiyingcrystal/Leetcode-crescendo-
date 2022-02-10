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

    int countComponents(int n, vector<vector<int> >& edges) {
        // special case
        if (!edges.size()) return n;
        // preprocessing
        unordered_map<int, unordered_set<int> > node_map;
        for (auto& edge : edges) {
            node_map[edge[0]].insert(edge[1]);
            node_map[edge[1]].insert(edge[0]);
        }
        // build queue, visited, color
        queue<int> q;
        unordered_set<int> visited;
        int color;
        // add loop
        for (int i = 0; i < n; i++) {
            // primitive
            if (visited.find(i) == visited.end()) {
                q.push(i);
                visited.insert(i);
                color += 1;
                // begin bfs
                while (!q.empty()) {
                    // fetch the first, pop, set color
                    int node = q.front();
                    q.pop();
                    for(auto& neighbor : node_map[node]) {
                        if (visited.find(neighbor) == visited.end()) {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                    }

                }
            }
        }
        return color; 
    }

};

int main() {
    return 0;
}