#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }

    int maxProfit(vector<int>& prices) {
        return 1;
    }
};

int main() {
    vector<int> price {7, 1, 5, 3, 6, 4};
    Solution* ss = new Solution();
    cout << ss->maxProfit(price) << endl;
}