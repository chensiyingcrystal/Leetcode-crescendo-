#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>


using namespace std;

class Solution {

public:
    Solution() {

    }

    int getMinCost(vector<int>& parcels, int k) {
        int n = parcels.size();
        if (n >= k) return 0;
        int need = k - n;

        unordered_set<int> has;
        for (int& parcel : parcels) {
            has.insert(parcel);
        }

        int minCost = 0;
        for (int i = 1; i <= INT_MAX; i++) {
            if (!has.count(i)) {
                has.insert(i);
                minCost += i;
                need--;
                if (need == 0) break;
            }
        }
        return minCost;
        
    }

};

int main() {
    vector<int> parcels = {2, 3, 6, 10, 11};
    int k = 9;
    Solution* ss = new Solution();
    int cost = ss->getMinCost(parcels, k);
    cout << cost << endl;
    return 0;
    
}

