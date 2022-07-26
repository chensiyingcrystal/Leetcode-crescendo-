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
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        vector<int> freq(128, 0);
        int maxLength = INT_MIN;
        
        while (right < n) {
            char c = s[right];
            freq[c]++;
            
            while (freq[c] > 1) {
                char c1 = s[left];
                freq[c1]--;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength == INT_MIN? 0 : maxLength;
    }

    
};