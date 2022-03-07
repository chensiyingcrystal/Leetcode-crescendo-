#include <vector>
#include <unordered_map>
#include <priority_queue>

using namespace std;

class Solution {
public:
    //time: nlogk; space: n+k
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int n = nums.size();
        //build hash map: element and its frequency
        unordered_map<int, int> fre;
        for (int i = 0; i < n; i++) {
            fre[nums[i]]++;
        }
        //initialize a min-heap with most frequent k elements; time: nlogk
        //pay attention to the lambda function here: use fre reference
        auto comp = [&fre](int a, int b) {
            return fre[a] > fre[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);

        //f的类型实际上是pair<int, int>
        for (auto& f : fre) {
            q.push(f.first);
            if (q.size() > k) {
                q.pop();
            }
        }

        // list<int> l;
        // l.push_back(q.top());
        // q.pop();
        // while (!q.empty()) {
        //     list<int>::iterator it = l.begin();
        //     l.insert(it, q.top());
        //     q.pop();
        // }

        //build an output array: time: klogk
        //直接定义ans的大小 然后根据索引
        vector<int> ans(k);
        while (!q.empty()) {
            ans[--k] = q.top();
            q.pop();
        }

        return ans;
    }
};