#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long> minimumCost(vector<int>& red, vector<int>& blue, int blueCost) {
        vector<long> ans(red.size() + 1);
        ans[0] = 0;
        bool flag = true;
        for (int i = 1; i < red.size() + 1; i++) {
            long redCost = ans[i - 1] + red[i - 1];
            long blueCost = flag ? ans[i - 1] + blue[i - 1] + blueCost : ans[i - 1] + blue[i - 1];
            if (blueCost <= redCost) {
                ans[i] = blueCost;
                flag = false;
            }
            else {
                ans[i] = redCost;
                flag = true;
            }
        }
        return ans;
    }
};

int main() {
    Solution* ss = new Solution();
    vector<int> red = {5};
    vector<int> blue = {3};
    vector<long> res = ss->minimumCost(red, blue, 1);
    for (long& r : res) {
        cout << r << endl;
    }

}
