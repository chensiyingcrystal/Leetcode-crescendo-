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

    string AlienDictionary(vector<string>& words) {
        // special case
        if (words.empty()) return "";
        if (words.size() == 1) return words[0];
        // 构建拓扑图
        unordered_map<char, unordered_set<char> > topo;
        unordered_map<char, int> restrictions;
        Buildgraph(words, topo, restrictions);
        // 存储结果和指示器
        string result;
        int number = restrictions.size();
        // 初始化队列：确定初始元素
        queue<char> q;
        for(auto& c : restricions) {
            if (!restrictions[c]) {
                q.push(c);
                result += c;
            }
        }
        // 开始拓扑排序（bfs）
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

    
    void Buildgraph(vector<string>& words, unordered_map<char, unordered_set<char> >& topo, 
    unordered_map<char, int>& restrictions) {
         for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                int min_length = min(words[i].size(), words[j].size());
                for(int x = 0; x < min_length; x++) {
                    if (words[i][x] != words[j][x]) {
                        if (topo[words[i][x]].find(words[j][x]) == topo[words[i][x]].end()) {
                            topo[words[i][x]].insert(words[j][x]);
                            restrictions[words[j][x]] += 1;
                        }
                    }
                } 
            }
         }
    }
};

int main() {
    return 0;
}