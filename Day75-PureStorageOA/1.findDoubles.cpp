#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    void findDoubles(vector<int> arr) {
        map<int, int> numMap;
        for (auto& num : arr) {
            numMap[num]++;
        }

        for (auto& p : numMap) {
            int num = p.first, count = p.second;
            if (numMap.count(num * 2) && numMap[num * 2] == 1) {
                for (int i = 1; i <= count; i++) {
                    cout << num << endl;
                }
            }
        }
    }



};

int main() {
    Solution* ss = new Solution();
    vector<int> arr = {1,1,2};
    ss->findDoubles(arr);

    return 0;


}