#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size();
        const int n = text2.size();
        vector<int> longestsub(n, 0);

        for(int i = 0; i < n; ++i) {
            if (text1.find(text2[i]) == string::npos) continue;
            else {
                if (i == 0) longestsub[0] = 1;
                for(int j = 0; j < i; ++j) {
                    if (text1.find(text2[j]) != string::npos && text1.find(text2[i]) > text1.find(text2[j])) {
                        longestsub[i] = max(longestsub[i], longestsub[j] + 1);
                    }
                }
            } 
        }

        int longestlength = 0;
        for (auto x : longestsub) {
            longestlength = max(x, longestlength);
        }

        return longestlength;
    }

    // int longestCommonSubsequence(string text1, string text2) {
    //     const int m = text1.size();
    //     const int n = text2.size();
    //     vector<int> longestsub(n, 0);
    //     for(int p = 0; p < n; ++p) {
    //         if ((text1.find(text2[p]) != string::npos)) {
    //             longestsub[p] = 1;
    //         }
    //     }

    //     for(int i = 0; i < n; ++i) {
    //         if (text1.find(text2[i]) == string::npos) continue;
    //         else {
    //             for(int j = 0; j < i; ++j) {
    //                 if(text1.find(text2[i]) > text1.find(text2[j])) {
    //                     longestsub[i] = max(longestsub[i], longestsub[j] + 1);
    //                 }
    //             }
    //         } 
    //     }

    //     int longestlength = 0;
    //     for (auto x : longestsub) {
    //         longestlength = max(x, longestlength);
    //     }

    //     return longestlength;
    // }
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    Solution* ss = new Solution();
    int result = ss->longestCommonSubsequence(text1, text2);
    cout << result;
}