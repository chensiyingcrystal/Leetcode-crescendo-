#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findMaxDifference(string& s, vector<char>& need) {
        int n = s.length();
        int left = 0, right = 0;
        unordered_map<char, int> map;
        unordered_map<char, int> need_map;
        int maxDifference = INT_MIN;
        priority_queue<pair<char, int> > pq;
        




    }


};