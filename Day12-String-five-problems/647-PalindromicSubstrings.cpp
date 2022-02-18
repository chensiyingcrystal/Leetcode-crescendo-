#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {


    }

    int countSubstrings(string s) {
        const int n = s.size();
        int sum = 0;
        auto getNumber = [&](int left, int right) {
            int count = 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                count++;
            }
            //important: even case, not counting itself; odd case, counting itself
            return left == right? count : count - 1;
        };
        for (int i = 0; i < n; i++) {
            int num = getNumber(i, i) + getNumber(i, i + 1);
            sum += num;
        }
        return sum;
    }
};