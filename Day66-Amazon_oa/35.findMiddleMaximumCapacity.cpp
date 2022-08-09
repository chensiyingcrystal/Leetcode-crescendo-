#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    Solution() {

    }
    
    int findMiddleMaximumCapacity(vector<int> capacity) {
        int n = capacity.size();
        if (n < 3) return -1;
        unordered_map<int, int> map; // key: number, value: mark(0-not find factor, 2-find its factor)
        int middleMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sqr = (int)sqrt(capacity[i]);//sqrt generat double type
            for (int num = 1; num <= sqr; num++) {
                int temp = capacity[i] / num;
                if (capacity[i] % num == 0 && (map.count(num) || map.count(temp))) {
                    if (map.count(num) && map[num] == 2) {
                        middleMax = max(middleMax, num);
                    }
                    if (map.count(temp) && map[temp] == 2) {
                        middleMax = max(middleMax, temp);
                    }
                    map[capacity[i]] = 2; //not adding to map before checking map has sth to avoid this number to be added is the same as the number that we want to check.
                }
            }
            if (!map.count(capacity[i])) map[capacity[i]] = 0;
        }
        return middleMax == INT_MIN ? -1 : middleMax;
    }


};

int main() {
    Solution* ss = new Solution();
    vector<int> nums = {1, 2, 6, 4, 107, 109, 1024};
    int middleMax = ss->findMiddleMaximumCapacity(nums);
    cout << middleMax << endl;
    
    return 0;
}