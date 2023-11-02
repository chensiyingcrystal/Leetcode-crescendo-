#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findPatterNumber(vector<int> arr) {
        unordered_map<int, unordered_map<int, int>> countMap; 
        int preSum = 0, count = 0;
        for (int i = 0; i < arr.size(); i++) {
            int currPrefix = preSum + arr[i];
            int target = currPrefix - 2 * arr[i];
            if (countMap.count(target) && countMap[target].count(arr[i])) {
                count += countMap[target][arr[i]];
            }
            countMap[currPrefix][arr[i]] += 1;
            preSum = currPrefix;
        }
        return count;
    }



};

int main() {
    Solution* ss = new Solution();
    vector<int> arr = {3, 1, 2, 3, -1, 1, 4, -7, 3, -4, 1};
    int ans = ss->findPatterNumber(arr);
    cout << ans << endl;

    return 0;


}