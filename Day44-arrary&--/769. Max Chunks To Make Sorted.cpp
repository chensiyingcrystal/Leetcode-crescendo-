#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
//第一遍错误解法：误用dp
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        //map records two information for the arr ending at the elements of index i
        //map[i].first is the maximum value in the 0 to ith elements; 
        //map[i].second records the maximum chunks for the ith elements in the array
        unordered_map<int, pair<int, int> > map;
        //initialize map
        map[0].first = arr[0];
        map[0].second = 1;
        //the formula is:
        //if arr[i] > map[i-1].first: map[i].first = arr[i]; map[i].second = map[i-1].second + 1
        //if arr[i] < map[i-1].first: map[i].first = map[i-1].first; map[i].second = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > map[i - 1].first) {
                map[i].first = arr[i];
                map[i].second = map[i - 1].second + 1;
            }
            else {
                map[i].first = map[i - 1].first;
                map[i].second = 1;
            }
        }
        return map[n - 1].second;
    }
//第二遍自己写的解法：当前可以分割的条件：左边的最大值要小于元素右边的最小值
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        if (n == 1) return 1;
        int count = 0;
        //first loop to record the maximum value from 0 to ith elements
        vector<int> max_value(n - 1);
        max_value[0] = arr[0];
        for (int i = 1; i < n - 1; i++) {
            max_value[i] = max(arr[i], max_value[i - 1]);
        }
        //second loop from end to start recording minimum value from ith elements to the end
        vector<int> min_value(n - 1);
        min_value[n - 2] = arr[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            min_value[i] = min(arr[i + 1], min_value[i + 1]);
        }
        //third loop to count the chunks: add 1 if at ith elements
        //the maximum value is less than the minimum value
        for (int i = 0; i < n - 1; i++) {
            if (max_value[i] < min_value[i]) count++;
        }
        return count + 1;
    }
};