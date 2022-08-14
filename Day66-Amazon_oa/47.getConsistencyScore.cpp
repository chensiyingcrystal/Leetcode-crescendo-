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


    int getConsistencyScore(vector<int> price, int k) {
        int n = price.size(), left = 0, right = 0;
        unordered_map<int, int> visited;
        int historyMax = INT_MIN;
        int ans = INT_MIN;

        while (right < n) {
            visited[price[right]]++;
            historyMax = max(historyMax, visited[price[right]]);
            int replace = right - left + 1 - historyMax;

            while (replace > k) {
                visited[price[left]]--;
                left++;
                replace = right - left + 1 - historyMax;
            }

            ans = max(ans, historyMax);
            right++;
        }

        return ans;
    }

    

};

int main() {
    Solution* ss = new Solution();
    vector<int> num = {7, 5, 7, 7, 1, 1, 7, 7};
    int pos = ss->getConsistencyScore(num, 3);
    cout << pos << endl;
    return 0;


}