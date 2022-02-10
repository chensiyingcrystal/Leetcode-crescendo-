#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    string AlienDictionary(vector<string>& words) {
        unordered_map<char, vector<int> > topo;
        unordered_map<char, int> restrictions;
        queue<char> q;
        string result;
        //node and edge
        Buildgraph(words, topo, restrictions);
        int number = restrictions.size();
        //topological sort
        for(auto& c : restricions) {
            if (!restrictions[c]) {
                q.push(c);
                result += c;
            }
        }
        while(!q.empty()) {
            char smaller = q.front();
            q.pop();
            number --;
            for(auto& neighbor : topo[smaller]) {
                restrictions[neighbor] --;
                if (!restrictions[neighbor]) {
                    q.push(neighbor);
                    result += neighbor;
                }

            }
        }
        return number == 0? result : "";
    }

    // don't know how to avoid duplication
    void Buildgraph(vector<string>& words, unordered_map<char, vector<int> >& topo, 
    unordered_map<char, int> restrictions) {
         for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                int min_length = min(words[i].size(), words[j].size());
                for(int x = 0; x < min_length; x++) {
                    if (words[i][x] != words[j][x]) {
                        topo[words[i][x]].push_back(words[j][x]);
                        restrictions[words[j][x]] += 1;
                    }
                } 
            }
         }
    }
};

int main() {
    return 0;
}