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
//上述代码改进: 不需要三次循环；不需要第二遍额外的空间；不需要i=1作为初始值
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        int count = 0;
        //first loop to record the maximum value from 0 to ith elements
        vector<int> max_value(n);
        max_value[0] = arr[0];
        //从头开始循环至结尾
        for (int i = 1; i < n; i++) {
            max_value[i] = max(arr[i], max_value[i - 1]);
        }
        //second loop from end to start recording minimum value from ith elements to the end
        //不再占用空间，因为只需要判断即可
        //利用左边一个数字为止的最大值和包含当前元素以及右边元素的最小值进行判断
        //或者利用包含当前数字以及向左的最大值和不包含当前元素及其右边的最小值进行判断
        int min_value = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (max_value[i] < min_value) count++;
            min_value = min(min_value, arr[i]);
        }
        return count;
    }
//简单解法：贪心？
//由于数组是0到n-1的排列，那么在i元素的位置，从0到i的元素最大值一定会大于或等于i（因为比它小的元素最多只有i-1个）
//当从0到当前元素的最大值大于i的时候，i元素的右边数组中必然有一个元素小于或等于i（因此肯定也比该最大值要小）
//这样左边元素的最大值不见得小于右边数组的最小值，肯定不能在i位置切分
//因此只有当前最大值恰好等于i的时候，才能完成一次切分
    int maxChunksToSorted(vector<int>& arr) {
        const int n = arr.size();
        int max_value = INT_MIN, count = 0;
        for (int i = 0; i < n; i++) {
            max_value = max(max_value, arr[i]);
            if (max_value == i) count++;
        }
        return count;
    }
};