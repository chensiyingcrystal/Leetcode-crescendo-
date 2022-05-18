#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //special case: empty string
        if (s.length() != t.length()) return false;
        unordered_map<char, int> map;
        for (auto& ch : s) {
            map[ch]++;
        }

        for (auto& ch : t) {
            if (!map.count(ch)) return false;
            map[ch]--;
        }

        for (auto& pair : map) {
            if (pair.second > 0) return false;
        }

        return true;
    }


};