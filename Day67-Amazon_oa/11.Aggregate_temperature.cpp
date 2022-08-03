#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>


using namespace std;

class Solution {

public:
    Solution() {

    }

    long long findMaxAggregateTemperature(vector<int>& changes) {
        long long maxAns = INT_MIN;
        //loop through changes find suffix sum
        int n = changes.size();
        vector<long long> suffix(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = (i == n - 1)? changes[i] : (long long)suffix[i + 1] + changes[i];
        }
        //loop through changes, add prefix sum and calcualte max aggregate temperature
        long long prefixSum;
        for (int i = 0; i < n; i++) {
            prefixSum = (i == 0)? changes[i] : prefixSum + changes[i];
            long long larger = max(prefixSum, suffix[i]);
            maxAns = max(maxAns, larger);
        }
        return maxAns;

    }

};

int main() {
    vector<int> temperatures = {6, -2, 5};
    Solution* ss = new Solution();
    int temp = ss->findMaxAggregateTemperature(temperatures);
    cout << temp << endl;
    
    vector<int> temperatures2 = {-1, 2, 3};
    int temp2 = ss->findMaxAggregateTemperature(temperatures2);
    cout << temp2 << endl;
    return 0;
    
}

