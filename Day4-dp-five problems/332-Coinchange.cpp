#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {

    }
    int coinChange(vector<int>& coins, int amount) {
        
    }
};


int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int amount = 11;
    Solution* ss = new Solution();
    int result = ss->coinChange(coins, amount);
    cout << result;
}