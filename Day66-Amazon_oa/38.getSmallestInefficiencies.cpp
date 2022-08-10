#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    Solution() {

    }
    
    vector<int> getSmallestInefficiencies(vector<int> skill, int k) {
        sort(skill.begin(), skill.end());
        auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
            return abs(skill[a.first] - skill[a.second]) > abs(skill[b.first] - skill[b.second]);
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> pq(comp); 
        set<pair<int, int> > visited;
        vector<int> ans;
        
        int n = skill.size();
        for (int i = 0; i < n - 1; i++) {
            pq.push({i, i + 1});
            visited.insert({i, i + 1});
        }

        while (ans.size() < k) {
            pair<int, int> temp = pq.top();
            pq.pop();
            int diff = abs(skill[temp.first] - skill[temp.second]);
            ans.push_back(diff);

            pair<int, int> next1, next2;
            if (temp.first != 0) {
                next1 = {temp.first - 1, temp.second};
                if (!visited.count(next1)) {
                    pq.push(next1);
                    visited.insert(next1);
                }
            }

            if (temp.second != n - 1) {
                next2 = {temp.first, temp.second + 1};
                if (!visited.count(next2)) {
                    pq.push(next2);
                    visited.insert(next2);
                }
            }
        }

        return ans;
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> power = {6, 9, 1};
    vector<int> middleMax = ss->getSmallestInefficiencies(power, 3);
    for (int& num : middleMax) {
        cout << num << endl;
    }
    
    return 0;
}