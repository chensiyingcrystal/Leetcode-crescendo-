#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
//topoligical sort
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        //base case
        if (n <= 2) {
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        //build ajacency list
        unordered_map<int, unordered_set<int> > neighbor;
        for (vector<int> edge : edges) {
            neighbor[edge[0]].insert(edge[1]);
            neighbor[edge[1]].insert(edge[0]);
        }

        //istantiate a queue
        queue<int> q;
        for (auto& p : neighbor) {
            if (p.second.size() == 1) {
                q.push(p.first);
            }
        }

        //begin bfs
        while (neighbor.size() > 2) {
            int n = q.size();
            while (n--) {
                int tmp = q.front();
                q.pop();
                //bug: first edge then erase node
                //bug: loop through only edges of the node instead of all nodes' edges
                //bug: cannot use int& here(non-const bind to const, because of p is key?)
                for (int p : neighbor[tmp]) {
                    neighbor[p].erase(tmp);
                    if (neighbor[p].size() == 1 && neighbor.size() > 2) {
                        q.push(p);
                    }
                }
                neighbor.erase(tmp);
            }
        }

        //return the left nodes in the graph list
        vector<int> ans;
        //bug: p is a pair
        for(auto& p : neighbor) {
            ans.push_back(p.first);
        }
        return ans;
    }
//自己写的，超时的解法，o(n2)
    vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        unordered_map<int, vector<int> > min_heights;
        vector<int> visited(n);
        for (int i = 0; i < n; i++) {
            unordered_map<int, vector<int> > children;
            findChildren(i, n, edges, children);
            min_heights[dfs(i, children)].push_back(i);
        }

        int min_height = INT_MAX;
        for (auto& p : min_heights) {
            min_height = min(p.first, min_height);
        }
        return min_heights[min_height]; 
    }

    void findChildren(int root, int n, vector<vector<int> >& edges, unordered_map<int, vector<int> >& children) {
        queue<int> q;
        vector<int> visited(n);
        q.push(root);
        visited[root] = 1;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == tmp) {
                    if (visited[edges[i][1]] != 1) {
                        q.push(edges[i][1]);
                        visited[edges[i][1]] = 1;
                        children[tmp].push_back(edges[i][1]);
                    }
                }
                else if (edges[i][1] == tmp) {
                    if (visited[edges[i][0]] != 1) {
                        q.push(edges[i][0]);
                        visited[edges[i][0]] = 1;
                        children[tmp].push_back(edges[i][0]);
                    }
                }
            }
        }
    }

    int dfs(int i, unordered_map<int, vector<int> >& children) {
        if (children[i].empty()) return 0;
        
        int h = INT_MIN;
        for (int x = 0; x < children[i].size(); x++) {
            h = max(h, dfs(children[i][x], children));
        }

        return h + 1;
    }

};