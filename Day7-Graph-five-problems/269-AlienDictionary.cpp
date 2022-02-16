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
        // 构建拓扑图
        unordered_map<char, unordered_set<char> > topo;
        unordered_map<char, int> restrictions; 
        //返回空字符串的第一种情况，拓扑图没有有效建立，在函数中返回false
        //第二种情况即为循环，这个会在拓扑排序的bfs中产生结果    
        if (!buildGraph(words, topo, restrictions)) return "";
        // 构建存储结果和指示器
        string result;
        int number = restrictions.size();
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
            //取出元素并删除
            char cur = q.front();
            q.pop();
            //计数器工作
            number --;
            //对满足条件的邻居进行操作
            for(auto& neighbor : topo[cur]) {
                restrictions[neighbor] --;
                if (restrictions[neighbor] == 0) {
                    q.push(neighbor);
                    result.push_back(neighbor);
                }
            }
        }
        //返回计数器结果，出现第二种返回空字符串的情况
        return number == 0? result : "";
    }

    bool buildGraph(vector<string>& words, unordered_map<char, unordered_set<char> >& topo, 
    unordered_map<char, int>& restrictions) {
        //构建所有字符序列，没有比较过的也统计进入（符合题目中所说的没有解的时候返回任意解）
        //即对于ab abcfk，这种情况，逻辑上valid，因此并不返回空字符串；但是由于字母顺序未知，因此返回任意序列都会通过test
        //即对于所有字母来说，在拓扑图中受约束数量都为0，每个节点都没有邻居
        //但是对于abcfk ab这种情况，逻辑上并不成立，因为ab明显更短，却排在前面，因此要返回false
        //这个模块还有个功能，即统计所有节点数，作为unique元素加入hashmap的，最后hashset的总数为node总个数
        for (auto& word : words) {
            for (auto& c : word) {
                restrictions[c] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            string self = words[i];
            string next = words[i + 1];
            // 检查是否会出现abb ab的情况
            if(self.size() > next.size() && self.substr(0, next.size()) == next) return false;
            //只对相邻两个元素检查即可
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