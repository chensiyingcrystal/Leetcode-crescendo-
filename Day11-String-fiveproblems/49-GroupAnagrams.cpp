#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }
//solution1: sort each word and then group

//brute force, will tle
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        //build visited, result
        vector<int>visited(strs.size(), 0);
        vector<vector<string> > result;
        //loop through each element to see if one is another's anagram
        for (int i = 0; i < strs.size(); i++) {
            if (visited[i] == 0) {
                vector<string> result_of_i;
                result_of_i.push_back(strs[i]);
                visited[i] = 1;
                for (int j = i + 1; j < strs.size(); j++) {
                    if (visited[j] == 0) {
                        if (anaGrams(strs[i], strs[j])) {
                            result_of_i.push_back(strs[j]);
                            visited[j] = 1;
                        }
                    }
                }
                result.push_back(result_of_i);
            }
        }
        return result;
    }

    bool anaGrams(string s, string t) {
        if (s.size() != t.size()) return false;
        int arr[26] = {0};
        for (char c : s) arr[c - 'a']++;
        for (char c : t) arr[c - 'a']--;
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }

};