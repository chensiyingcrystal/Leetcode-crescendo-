#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
//more intuitive method: find a "01" and "10" 
//and then expand around it, however the time complexity is o(n2)
    int countBinarySubstrings(string s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1' || s[i] == '1' && s[i + 1] == '0') {
                helper(s, i, count);
            }
        }
        return count;
    }

    void helper(string s, int i, int& count) {
        int n = s.length();
        int left = i, right = i + 1;
        char pre_left = s[left], pre_right = s[right];
        while (left >= 0 && right < n && s[left] == pre_left && s[right] == pre_right) {
            count++;
            left--;
            right++;
        }
        return;
    }
//another method: preprocessing record the number of 0 or 1 groups;
//then for two groups: count = min(group(1), group(2));
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> group;

        int count = 0;
        char pre = s[0];
        for (int i = 0; i < n; i++) {
            if (s[i] == pre) count++;
            else {
                group.push_back(count);
                count = 1;
                pre = s[i];
            }
        }
        //bug: don't forget here to push the last group count into group vector
        group.push_back(count);

        int sum = 0;
        for (int i = 0; i < group.size() - 1; i++) {
            sum += min(group[i], group[i + 1]);
        }

        return sum;
    }

};