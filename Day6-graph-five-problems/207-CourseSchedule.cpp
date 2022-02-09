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
 
     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> input_map;
        unordered_map<int, vector<int> > output_map;
        for(int i = 0; i < prerequisites.size(); ++i) {
            input_map[prerequisites[i][0]] += 1;
            output_map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(input_map.find(i) == input_map.end()) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            numCourses --;
            if(output_map.find(temp) != output_map.end()) {
                for(auto& output : output_map[temp]) {
                    //redundant clause
                    // if(input_map.find(output) != input_map.end()) {
                    input_map[output] --;
                    // }
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