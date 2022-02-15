#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    string alienOrder(vector<string>& words) {
        // special case
        if (words.empty()) return "";
        if (words.size() == 1) return words[0];
        // 构建拓扑图
        unordered_map<char, unordered_set<char> > topo;
        unordered_map<char, int> restrictions;
        // 构建存储结果和指示器
        string result;
        for (auto& word : words) {
            for (auto& c : word) {
                restrictions[c] = 0;
            }
        }
        int number = restrictions.size();
        // 构建拓扑图        
        if (!buildGraph(words, topo, restrictions)) return "";
        // 初始化队列：确定初始元素
        queue<char> q;
        for(auto c : restrictions) {
            if (c.second == 0) {
                q.push(c.first);
                result.push_back(c.first);
            }
        }
        // 开始拓扑排序（bfs）
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            number --;
            for(auto& neighbor : topo[cur]) {
                restrictions[neighbor] --;
                if (restrictions[neighbor] == 0) {
                    q.push(neighbor);
                    result.push_back(neighbor);
                }
            }
        }
        return number == 0? result : "";
    }

    bool buildGraph(vector<string>& words, unordered_map<char, unordered_set<char> >& topo, 
    unordered_map<char, int>& restrictions) {
        for(int i = 0; i < words.size() - 1; i++) {
            string self = words[i];
            string next = words[i + 1];
            // 检查是否会出现ab abb的情况
            if(self.size() < next.size() && next.substr(0, self.size()) == self) return false;
            for (int j = 0; j < min(self.size(), next.size()); j++) {
                if (self[j] != next[j]) {
                    if (topo[self[j]].find(next[j]) == topo[self[j]].end()) {
                        topo[self[j]].insert(next[j]);
                        restrictions[next[j]] += 1;
                    }
                    break;
                }
            }
        }
        return true;
    }

    // 为什么只用比较相邻的？
    // void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char> >& topo, 
    // unordered_map<char, int>& restrictions) {
    //      for(int i = 0; i < words.size(); i++) {
    //         for(int j = i + 1; j < words.size(); j++) {
    //             int min_length = min(words[i].size(), words[j].size());
    //             for(int x = 0; x < min_length; x++) {
    //                 if (words[i][x] != words[j][x]) {
    //                     if (topo[words[i][x]].find(words[j][x]) == topo[words[i][x]].end()) {
    //                         topo[words[i][x]].insert(words[j][x]);
    //                         restrictions[words[j][x]] += 1;
    //                     }
    //                     break;
    //                 }
    //             } 
    //         }
    //      }
    // }
};

int main() {
    return 0;
}