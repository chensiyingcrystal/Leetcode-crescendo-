#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    Solution() {

    }

    int findMinPressCount(string s) {
        if (s.length() == 0) return 0;
        vector<int> freq(26);
        //store each character's frequency
        for (char& c : s) {
            freq[c - 'a']++;
        }
        //sort in decreasing order according to each character's frequency
        sort(freq.begin(), freq.end(), [](int& a, int& b) {
            return a > b;
        });
        //loop through sorted freq to determine the minimum press
        int minPress = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            minPress += freq[i] * (i / 9 + 1);
        }
        return minPress;





    }
};