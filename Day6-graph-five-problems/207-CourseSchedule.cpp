#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     unordered_map<int, int> input_map;
    //     for(int i = 0; i < prerequisites.size(); ++i) {
    //         input_map[prerequisites[i][0]] += 1;
    //     }
    //     queue<int> q;
    //     for(int i = 0; i < numCourses; i++) {
    //         if(input_map.find(i) == input_map.end()) {
    //             q.push(i);
    //         }
    //     }
    //     if(q.empty()) return false;
    //     while (!q.empty()) {
    //         int temp = q.front();
    //         q.pop();
    //         for(int i = 0; i < prerequisites.size(); ++i) {
    //             if(prerequisites[i][1] == temp) {
    //                 input_map[prerequisites[i][0]] -= 1;
    //             }
    //         }
    //         for(auto& n : input_map) {
    //             if (input_map[n] == 0) q.push(n);
    //         }
    //     }
    //     for(auto& n : input_map) {
    //         if(input_map[n] != 0) return false;
    //     }
    //     return true;
    // }
 
     bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        // 构建拓扑图：节点的受约束数量和约束节点对被约束节点的映射表
        unordered_map<int, int> input_map;
        unordered_map<int, vector<int> > output_map;
        for(int i = 0; i < prerequisites.size(); ++i) {
            input_map[prerequisites[i][0]] += 1;
            output_map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // 初始化队列，确定拓扑图的开始节点
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(input_map.find(i) == input_map.end()) {
                q.push(i);
            }
        }
        // 开始bfs
        while(!q.empty()) {
            // 从队列取出元素并删除
            int temp = q.front();
            q.pop();
            // 指示的计数器开始更新
            numCourses --;
            // 对节点的邻居操作：删除节点的边，与此同时受约束节点的受限制数量减1，如果转变为0，将其添加队列中
            if(output_map.find(temp) != output_map.end()) {
                for(auto& output : output_map[temp]) {
                    input_map[output] --;
                    // 添加入队列的两次机会：初始受限制数量为0，中途受限制数量转变为0
                    // 不需要检测该节点是否已经访问过，因为它如果没有在初始队列中添加，就一定不会与其重复
                    if(input_map[output] == 0) q.push(output);
                }
            }  
        }
        return numCourses == 0; 
    }

    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     unordered_map<int, int> input_map;
    //     unordered_map<int, vector<int>> output_courses;
    //     for(int i = 0; i < prerequisites.size(); ++i) {
    //         input_map[prerequisites[i][0]] += 1;
    //         output_courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
    //     }
    //     queue<int> q;
    //     for(int i = 0; i < numCourses; i++) {
    //         if(input_map.find(i) == input_map.end()) {
    //             q.push(i);
    //         }
    //     }
    //     while (!q.empty()) {
    //         int temp = q.front();
    //         q.pop();
    //         numCourses --;
    //         if (output_courses.count(temp)) {
    //             for (auto& output : output_courses[temp]) {
    //                 input_map[output]--;
    //                 if (input_map[output] == 0) {
    //                     q.push(output);
    //                 }
    //             }
    //         }
    //     }
    //     return numCourses == 0;
    // }

}

int main() {
    return 0;
}