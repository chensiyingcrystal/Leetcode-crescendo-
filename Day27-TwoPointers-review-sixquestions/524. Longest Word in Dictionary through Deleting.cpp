#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //loop through dictionary, to check each word with string
        string ans = "";
        for (int i = 0; i < dictionary.size(); i++) {
            //initialize two pointer, p for the word in dictionary, q for string s
            int p = 0, q = 0;
            while (q < s.length()) {
                if (dictionary[i][p] == s[q]) {
                    p++;
                    q++;
                }
                q++;
            }
            
            //check if we found the word matches with string s 
            if (p >= dictionary[i].length()) {
                if (dictionary[i].length() > ans.length() || dictionary[i] < ans) {
                    ans = dictionary[i];
                }
            }
        }

        return ans == ""? "" : ans;

    } 
};