#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:

    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0; i < s.length(); i++) {
            if (map.count(s[i])) {
                if (map[s[i]] != t[i]) return false;
            }
            else {
                map[s[i]] = t[i];
            }
        }
        return true;
    }

};