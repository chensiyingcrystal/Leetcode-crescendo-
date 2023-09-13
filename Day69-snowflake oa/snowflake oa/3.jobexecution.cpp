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
//discussion: https://leetcode.com/company/snowflake/discuss/3479190/SnowFlake-OA-Job-Execution
    int getMinimumOperations(vector<int>& executionTime, int& x, int& y) {
        //use binary search to find the minimum operation 
        int left = 1, right = *max_element(executionTime.begin(), executionTime.end());
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<int> copyOfExectionTime(executionTime.begin(), executionTime.end());
            if (canComplete(copyOfExectionTime, x, y, mid)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }

        }
        return ans;
    }

    bool canComplete(vector<int>& executionTime, int& x, int& y, int& operation) {
        //each job minus y * operation
        for (int i = 0; i < executionTime.size(); i++) {
            executionTime[i] -= y * operation;
        }

        //for each job with left time greater than 0, we need to sum up its left time calculated by e/(x-y) 
        int operationSum = 0;
        for (int i = 0; i < executionTime.size(); i++) {
            if (executionTime[i] > 0) {
                int curr = executionTime[i] % (x - y) == 0 ? executionTime[i] / (x - y) : executionTime[i] / (x - y) + 1;
                operationSum += curr;
            }
        }
        return operationSum <= operation;

    }






    

};

int main() {
    Solution* ss = new Solution();
    vector<int> executionTime = {3, 4, 1, 7, 6};
    int x = 4, y = 2;
    int ans = ss->getMinimumOperations(executionTime, x, y);

    cout << ans << endl;
    return 0;


}