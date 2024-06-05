#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <priority_queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    void FindRacerResults(vector<vector<int>> raw_data) {
        map<int, int> scores;
        for (int i = 0; i < raw_data.size(); i++) {
            int record_number = raw_data[i][1], point = raw_data[i][2];
            if (point == 1) {
                scores[record_number] += 10;
            } else if (point == 2) {
                scores[record_number] += 6;
            } else if (point >= 3 && point <= 6) {
                scores[record_number] += 7 - point;
            } else {
                scores[record_number] += 0;
            }
        }
        
        auto comp = [&](int& a, int& b) {
            if (scores[a] != scores[b]) {
                return scores[a] < scores[b];
            } else {
                return a > b;
            };
        }
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto& p : scores) {
            pq.push(p.first);
        }

        if (!pq.empty()) {
            int winner_number = pq.top(), winner_score = scores[pq.top()];
            cout << winner_number << " " << winner_score << endl;
        }

        for (auto& p : scores) {
            if (p.second == 0) {
                cout << p.first << " ";
            }
        }

    }



};

int main() {
    Solution* ss = new Solution();
    

    return 0;


}