#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   Solution() {

   }


    int count_one(uint32_t j) {
        int times = 0;
        while (j) {
            int module = j & 1;
            if (module) {
                times += 1;
            }
            j = j >> 1;
        }
        return times;
    }


    vector<int> countBits(int n) {
        vector<int> output;
        for(int i = 0; i <=n; ++i) {
            int times_i = count_one(i);
            output.push_back(times_i);
        }
        return output;
    }

};


int main() {
    Solution* ss = new Solution();
    vector<int> result = ss->countBits(2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}