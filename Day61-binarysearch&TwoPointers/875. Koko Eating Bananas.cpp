#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
//key: recognize this is a binary search problem
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        //easy way to calculate maximum numbers in a vector
        int max_pile = *max_element(piles.begin(), piles.end());
            
        int left = 1, right = max_pile;
        int ans = max_pile;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool res = canEatAll(piles, h, mid);
            if (res) {
                //do not leave mid!
                //Here we can also use left < right and right = mid
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
        
    }

    bool canEatAll(vector<int>& piles, int h, int mid) {
        long hour = 0;
        for (int i = 0; i < piles.size(); i++) {
            hour += (long)piles[i] / mid;
            if (piles[i] % mid != 0) {
                hour += 1;
            }
        }
        return hour <= h;
    }
};