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

    int findEarliestMonth(vector<int>& prices) {
        int minAverage = INT_MAX, month;
        int n = prices.size();
        vector<long long> suffix(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (i == n - 1)? 0 : (long long)(suffix[i + 1] + prices[i + 1]);
        }
        
        long long prefix = 0;
        for (int i = 0; i < n - 1; i++) {
            prefix += prices[i];
            int netPrice = abs(prefix / (i + 1) - suffix[i] / (n - i - 1));
            if (netPrice < minAverage) {
                minAverage = netPrice;
                month = i + 1;
            }
        }
        return month;
 
    }

    

};

int main() {
    Solution* ss = new Solution();
    vector<int> stock = {1, 3, 2, 3};
    int pos = ss->findEarliestMonth(stock);
    cout << pos << endl;


}