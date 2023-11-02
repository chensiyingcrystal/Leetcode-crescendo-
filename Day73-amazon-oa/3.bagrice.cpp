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

    int riceBags(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLen = 0;
        for (auto& num : numSet) {
            if (!numSet.count(num * num)) {
                int len = 0, currNum = num;
                while (numSet.count(currNum)) {
                    len++;
                    int curr = currNum;
                    currNum = (int) sqrt(currNum);
                    if (currNum * currNum != curr) break;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen > 1 ? maxLen : -1;
        
    }



};

int main() {
    Solution* ss = new Solution();
    vector<int> arr = {625, 4, 2, 5, 25, 8, 64, 4096};
    int ans = ss->riceBags(arr);
    cout << ans << endl;

    return 0;


}