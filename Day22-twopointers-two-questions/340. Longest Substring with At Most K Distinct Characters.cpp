#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
//76题的变形，学会用count和vector<int>track unique character
//如果用hash map或者set，可以用erase（key）移除元素
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int left = 0, right = 0;
        int count = 0;
        vector<int> unique(128);
        int max_length = INT_MIN;
        while (right < s.length()) {
            char c = s[right];
            if (unique[c]++ == 0) count++;

            while (count > k) {
                char x = s[left];
                if (--unique[x] == 0) count--;
                //bug: don't forget the incrementing step!
                left++;
            }

            int length = right - left + 1;
            max_length = max(max_length, length);

            right++;
        }
        return max_length;
    }


};