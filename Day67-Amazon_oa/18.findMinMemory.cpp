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

    int findMinMemory(vector<int>& processes, int m) {
        //calculate sum of all memories
        int memorySum = 0;
        for (int& p : processes) {
            memorySum += p;
        }
        //calculate max window sum of size m
        int left = 0, right = 0;
        int maxWindow = INT_MIN, temp = 0;
        while (right < processes.size()) {
            temp += processes[right];
            while (right - left + 1 > m) {
                temp -= processes[left];
                left++;
            }
            if (right - left + 1 == m) {
                maxWindow = max(maxWindow, temp);
            }
            right++;
        }
        return memorySum - maxWindow;

    }

    

};

int main() {
    Solution* ss = new Solution();
    vector<int> stock = {7, 3, 6, 1};
    int pos = ss->findMinMemory(stock, 2);
    cout << pos << endl;


}