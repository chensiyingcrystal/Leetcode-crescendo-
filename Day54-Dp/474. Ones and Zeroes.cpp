#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //1. preprocessing the vector and get the number of 1s in each element and the total mount of characters in each string
        const int n = strs.size();
        vector<int> length(n);
        vector<int> ones(n);
        for (int i = 0; i < n; i++) {
            length[i] = strs[i].length();

            int one_count = 0;
            for (auto& c : strs[i]) {
                if (c == '1') one_count++;
            }
            ones[i] = one_count;
        }

        //2. build the dynamic programming model
        //
    }
};