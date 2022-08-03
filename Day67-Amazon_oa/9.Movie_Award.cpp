#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {

public:
    Solution() {

    }
    
    int findMinimumGroup(vector<int>& awards, int k) {
        int count = 0;
        sort(awards.begin(), awards.end());
        int i = 0, n = awards.size();
        while (i < n) {
            int first = awards[i];
            count++;
            int j = i + 1;
            while (j < n && awards[j] - first <= k) {
                j++;
            }
            i = j;
        }
        return count;

    }


};