#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
//This question requires using helper function
//The map direction is from left to right, one left to one right, no one character to two different characters
//In the other way, to check if no two different characters to one character, 
//we have to reverse s and t in another function
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }

    bool helper(string s, string t) {
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