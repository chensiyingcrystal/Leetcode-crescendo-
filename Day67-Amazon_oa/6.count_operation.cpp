#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    Solution() {

    }

    int countMaximumOperations(string& s, string& t) {
        if (s.length() < t.length()) return 0;
        int minAns = INT_MAX;
        //calculte frequency of each character in s and t
        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;
        for (char& c1 : s) {
            freqS[c1]++;
        }
        for (char& c2 : t) {
            freqT[c2]++;
        }
        //calculate maximum number of operations
        for (auto& p : freqT) {
            if (!freqS.count(p.first) || freqS[p.first] < p.second) return 0;
            minAns = min(minAns, freqS[p.first] / p.second);
        }
        return minAns;
    }












    }
};