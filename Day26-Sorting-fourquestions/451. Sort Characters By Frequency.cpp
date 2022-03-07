#include <vector>
#include <unordered_map>
#include <priority_queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        //build a hash map, record elements and their frequencies
        unordered_map<char, int> fre;
        for (char& ch : s) {
            fre[ch]++;
        }

        //initialize a priority queue, sorting the character based on their frequencies
        auto comp = [&fre](int a, int b) {
            return fre[a] < fre[b];
        };
        priority_queue<char, vector<char>, decltype(comp)> q(comp);
        for (auto& f : fre) {
            q.push(f.first);
        }

        //generate output string
        string ans = "";
        while (!q.empty()) {
            char c = q.top();
            //注意string里面重复字符的写法：不能用‘*’
            ans += string(fre[c], c);
            q.pop();
        }
        return ans;
    }
};