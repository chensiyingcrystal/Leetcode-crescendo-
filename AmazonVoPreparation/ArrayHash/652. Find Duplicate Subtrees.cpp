#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store each number's frequency in hash map
        unordered_map<int, int> map;
        for(int& num : nums) {
            map[num]++;
        }
        //maintain a min heap of size k and push all unique elements with its frequency into it
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> pq(comp);
        for (auto& p : map) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        //push all numbers in the queue into our ans
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }

//bucket sort 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //calculate each number's frequency
        unordered_map<int, int> map;
        for (int& num : nums) {
            map[num]++;
        }
        //use bucket sort to sort number based on its frequency
        int maxFreq = -1;
        for (auto& p : map) {
            maxFreq = max(maxFreq, p.second);
        }
        vector<vector<int> > buckets(maxFreq + 1);
        for (auto& p : map) {
            buckets[p.second].push_back(p.first);
        }
        //push k elements in the buckets to our ans
        vector<int> ans;
        for (int i = buckets.size(); i >= 0; i--) {
            for (int& num : buckets[i]) {
                if (ans.size() == k) return ans;
                ans.push_back(num);
            }
        }
        return ans;

    }

};