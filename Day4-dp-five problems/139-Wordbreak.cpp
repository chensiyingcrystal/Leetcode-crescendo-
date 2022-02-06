#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        for(auto x : wordDict) dict[x] = 1;
        const int n = s.size();
        vector<bool> result(n + 1, false);
        result[0] = true;
        for(int i = 1; i < n + 1; ++i) {
            string str = "";
            for(int j = i - 1; j >= 0; --j) {
                str = s[j] + str;
                if(dict.count(str)) {
                    int length = str.size();
                    result[i] = result[i - length];
                }
            }
        }
        return result[n];
    }

    //     bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_map<string, int> dict;
    //     int max_length = 0;
    //     for(auto x : wordDict) {
    //         dict[x] = 1;
    //         if (x.size() > max_length) {
    //             max_length = x.size();
    //         }
    //     }
    //     const int n = s.size();
    //     vector<bool> result(n + 1, false);
    //     result[0] = true;
    //     for(int i = 1; i < n + 1; ++i) {
    //         string str = "";
    //         for(int j = i - 1; j >= 0 && j >= i - max_length; --j) {
    //             str = s[j] + str;
    //             if(dict.count(str)) {
    //                 int length = str.size();
    //                 result[i] = result[i] | result[i - length];
    //             }
    //         }
    //     }
    //     return result[n];
    // }

}

int main() {
    vector<string> wordDict;
    wordDict.push_back("apple");
    wordDict.push_back("pen");
    string s;
    s = "applepenapple";
    Solution* ss = new Solution();
    bool result = ss->wordBreak(s, wordDict);
    cout << result << endl;
    return 0;
}