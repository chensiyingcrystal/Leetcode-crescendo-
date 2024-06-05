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

    int CountPairs(vector<int> arr, int diff) {
        //array is sorted, without duplicates
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] - arr[i] == diff) {
                    res++;
                } else if (arr[j] - arr[i] > diff) {
                    break;
                }
            }
        }
        return res;
        
    }



};

int main() {
    Solution* ss = new Solution();
    string s = "AB", l = "ABCABCEEABABDSFAB";
    int ans = ss->FindRepetition(s, l);
    cout << ans << endl;
    

    return 0;


}