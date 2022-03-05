#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        if (n == 1) return 1;
        //create a vector to record candies each children can get
        vector<int> candies(n, 1);

        //loop through the ratings to update candies based on the rule
        //break apart into two loops: first loop from left to right, each children looking at he/she's left side
        //because we wanna update our left side before the pointer comes to me(imagine like a ball coming from you from left)
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        //loop from right to left, each time we look at our right side
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candies[i + 1] >= candies[i]) {
                candies[i] = candies[i + 1] + 1;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};