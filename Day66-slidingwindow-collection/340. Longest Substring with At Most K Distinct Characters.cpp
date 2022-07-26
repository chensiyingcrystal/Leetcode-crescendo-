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
//最优化的解：用vector和count
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        int n = s.length();
        int left = 0, right = 0;
        vector<int> uniqueChar(128, 0);
        int count = 0;
        int maxLength = INT_MIN;
        
        while (right < n) {
            char c = s[right];
            if (uniqueChar[c] == 0) count++;
            uniqueChar[c]++;
            
            while (count > k) {
                char c1 = s[left];
                uniqueChar[c1]--;
                if (uniqueChar[c1] == 0) count--;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
            
            right++;
        }
        
        return maxLength;

    }

};