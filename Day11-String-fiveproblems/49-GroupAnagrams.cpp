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
//time complexity: o(NKlogK) space: o(NK)(字符串与数字不同，每个字符都要占2字节)
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > group;
        vector<vector<string> > result;

        for (int i = 0; i < strs.size(); i++) {
            //bug点：sort是对string进行操作后，返回的是空值，所以不可直接对原字符sort，也不可sort后赋值
            string ch = strs[i];
            sort(ch.begin(), ch.end());
            group[ch].push_back(strs[i]);  
        }

        for (auto& pair : group) {
            //bug点，pair是key-value一对值，要访问key可以用.first, 要访问value就用.second
            result.push_back(pair.second);
        }
        return result;
    }

//interview recommended
//solution2: use 26 characters couting, and put every sorted word in a map
//time complexity: o(N*(K+26)) -> o(NK) space: o(NK + N*26)
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        unordered_map<string, vector<string> > group;
        vector<vector<string> > result;

        for (string s : strs) {
            group[strSort(s)].push_back(s);
        }

        for (auto& pair : group) {
            result.push_back(pair.second);
        }

        return result; 
    }
    
    string strSort(string s) {
        int arr[26] = {0};
        for (char c : s) {
            arr[c - 'a']++;
        }
        
        string t;
        for (int x = 0; x < 26; x++) {
            t += string(arr[x], x + 'a');
        }
        return t;
    }


//brute force, will tle
    // vector<vector<string> > groupAnagrams(vector<string>& strs) {
    //     //build visited, result
    //     vector<int>visited(strs.size(), 0);
    //     vector<vector<string> > result;
    //     //loop through each element to see if one is another's anagram
    //     for (int i = 0; i < strs.size(); i++) {
    //         if (visited[i] == 0) {
    //             vector<string> result_of_i;
    //             result_of_i.push_back(strs[i]);
    //             visited[i] = 1;
    //             for (int j = i + 1; j < strs.size(); j++) {
    //                 if (visited[j] == 0) {
    //                     if (anaGrams(strs[i], strs[j])) {
    //                         result_of_i.push_back(strs[j]);
    //                         visited[j] = 1;
    //                     }
    //                 }
    //             }
    //             result.push_back(result_of_i);
    //         }
    //     }
    //     return result;
    // }

    // bool anaGrams(string s, string t) {
    //     if (s.size() != t.size()) return false;
    //     int arr[26] = {0};
    //     for (char c : s) arr[c - 'a']++;
    //     for (char c : t) arr[c - 'a']--;
    //     for (int i = 0; i < 26; i++) {
    //         if (arr[i] != 0) return false;
    //     }
    //     return true;
    // }

};