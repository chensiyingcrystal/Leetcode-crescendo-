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

//题目: https://www.1point3acres.com/bbs/thread-1003435-1-1.html
//solution：https://www.1point3acres.com/bbs/thread-947692-1-1.html
    int getPerfectPairs(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            arr[i] = abs(arr[i]);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int end = helper(arr, 2 * arr[i], i);
            ans += max(0, end - i);
        }
        return ans;

    }

    int helper(vector<int>& arr, int target, int& i) {
        int left = i + 1, right = arr.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                res = mid;
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } 
        }
        return res;


    }

    //reference java solution
//     public static int numberOfPair(int[] arr){
//         for (int i = 0; i < arr.length; i++){
//             if (arr[i] < 0) arr[i] = -arr[i];
//         }
//         Arrays.sort(arr);
//         int res = 0;
//         for (int i = 0; i < arr.length; i++){
//             int idx = bs(arr, arr[i] * 2);
//             res += Math.max(0, idx - i);
//         }
//         return res;
//     }
// // find the int x that arr[x] <= n < arr[x + 1]
// public static int bs(int[] arr, int n){
//     int sz = arr.length;
//     if (n <= arr[0]) return 0;
//     if (arr[sz - 1] <= n) return sz - 1;
//     int lo = 0;
//     int hi = sz - 1;
//     while (lo <= hi) {
//         int mid = (lo + hi) / 2;
//         if (n < arr[mid]) {
//             hi = mid - 1;
//         } else if (arr[mid] <= n && mid<sz-1 && n < arr[mid + 1] ) {
//             return mid;
//         } else {
//             lo = mid + 1;
//         }
//     }
//     return hi;
}

};

int main() {
    Solution* ss = new Solution();
    vector<int> arr = {2, 5, -3};
    int ans = ss->getPerfectPairs(arr);
    cout << ans << endl;

    return 0;


}