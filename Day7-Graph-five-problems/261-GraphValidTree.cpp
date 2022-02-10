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
    //Solution1: bfs
    bool validTree(int n, vector<vector<int> >& edges) {
        //special case
        if (!edges.size()) return n == 1;
        //preprocessing
        unordered_map<int, vector<int> > node_map;
        for(auto& edge : edges) {
            node_map[edge[0]].push_back(edge[1]);
            node_map[edge[1]].push_back(edge[0]);
        }
        //build queue and visited, to_be_visited
        unordered_set<int> visited;
        queue<int> q;
        unordered_set<int> to_be_visited;
        //primitive push value, set visited
        q.push(edges[0][0]);
        to_be_visited.insert(edges[0][0]);
        visited.insert(edges[0][0]);
        //couting tool
        int count = 0;
        //begin bfs
        while(!q.empty()) {
            //fetch the first node, pop, modify checking status, update the counting tool 
            int node = q.front();
            q.pop();
            to_be_visited.erase(node);
            count ++;
            //neighbor processing
            for(int neighbor : node_map[node]) {
                //check to see if any other decision related to the final result
                if(to_be_visited.count(neighbor)) return false;
                //visited or not, if not, add to queue and update its checking status
                if(!visited.count(neighbor)) {
                    q.push(neighbor);
                    to_be_visited.insert(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        //return counting tool results
        return count == n;
    }
};

int main() {
    return 0;
}