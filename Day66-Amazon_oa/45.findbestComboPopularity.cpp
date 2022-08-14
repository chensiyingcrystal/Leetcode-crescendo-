#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    Solution() {

    }

    vector<long> findBestComboList(vector<int> popularity, int k) {
        //count the total of all positive number in popularity
        int n = popularity.size();
        long total = 0;
        for (int& pop : popularity) {
            if (pop > 0) total += pop;
        }
        //turn all number in popularity to positive
        for (int& pop : popularity) {
            pop = abs(pop);
        }
        //sort popularity in non-decreasing order
        sort(popularity.begin(), popularity.end());
        //use min heap to find all kth less subset
        priority_queue<pair<long, int>, vector<pair<long, int> >, greater<pair<long, int>> > pq;
        pq.push({popularity[0], 0});
        vector<long> ans;
        ans.push_back(total);

        while (ans.size() < k) {
            pair<long, int> temp = pq.top();
            pq.pop();
            long pre = temp.first;
            int i = temp.second;
            ans.push_back(total - pre);
            if (i + 1 < n) {
                pq.push({pre + popularity[i + 1], i + 1});
                pq.push({pre - popularity[i] + popularity[i + 1], i + 1});
            }
         }

        return ans;



    }


    
};

int main() {
    Solution* ss = new Solution();
    vector<int> power = {3, 5, -2};
    vector<long> ans = ss->findBestComboList(power, 3);
    for (long& pair : ans) {
        cout << pair << endl;
    }
    
    return 0;
}