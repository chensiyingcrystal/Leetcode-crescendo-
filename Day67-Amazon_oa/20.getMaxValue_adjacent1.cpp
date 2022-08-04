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

    int getMaxValue(vector<int> arr) {
        sort(arr.begin(), arr.end());
        int preMin = 1;
        for (int i = 1; i < arr.size(); i++) {
            preMin = min(preMin + 1, arr[i]);
        }
        return preMin;
    }

};