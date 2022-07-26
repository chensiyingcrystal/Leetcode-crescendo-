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

    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int left = 0, right = 0; //often write right as the last character pointer
        unordered_map<char, int> map; //record each character's frequency
        int maxLength = INT_MIN; // don't forget to check out special case(don't even go into the loop)
        
        while (right < n) {
            char c = s[right];
            //do something to this current char(record its freq.)
            map[c]++;
            
            //move left pointer until it becomes valid
            while (map.size() > 2) { //condition: the indicator of invalid window
                char c1 = s[left];
                //delete this character before passing it(retrieving all the changes made on it)
                map[c1]--;
                if (map[c1] == 0) map.erase(c1);
                left++;
            }
            
            //record ans after a valid window checking
            maxLength = max(maxLength, right - left + 1);
            
            right++;
            
        }
        
        return maxLength;
    }
//优化：用变量count来记录distinct characters
//count增加的两种case：未存在过 或者存在但是frequency为0（以前擦除的痕迹）
//count减少的case：字符的frequency变为0
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int left = 0, right = 0; //often write right as the last character pointer
        unordered_map<char, int> map; //record each character's frequency
        int count = 0;
        int maxLength = INT_MIN; // don't forget to check out special case(don't even go into the loop)
        
        while (right < n) {
            char c = s[right];
            //do something to this current char(record its freq.)
            if (!map.count(c) || map[c] == 0) count++;
            map[c]++;
            
            //move left pointer until it becomes valid
            while (count > 2) { //condition: the indicator of invalid window
                char c1 = s[left];
                //delete this character before passing it(retrieving all the changes made on it)
                map[c1]--;
                if (map[c1] == 0) count--;
                left++;
            }
            
            //record ans after a valid window checking
            maxLength = max(maxLength, right - left + 1);
            
            right++;
            
        }
        
        return maxLength;
    }


};