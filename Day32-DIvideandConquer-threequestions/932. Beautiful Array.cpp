#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
//此题融合了数学和分治
//首先要使i+j！=2k，可使i为奇数，j为偶数，由于2k肯定为偶数，这样奇数+偶数肯定不会等于偶数
//每次将低层的数字each乘以2再-1就得到了高层的奇数，乘以2就得到了高层的偶数，按照奇数在左偶数在右拼起来就得到了高层
//将数字的长度从中间劈开，依次二分向下递归，直到base case即为1的情况
//利用map的memorization功能，优化时间复杂度`
    vector<int> beautifulArray(int n) {
        //initializing a map
        unordered_map<int, vector<int> > map;
        return helper(n, map);
    }
    
    vector<int> helper(int n, unordered_map<int, vector<int> >& map) {
        //first check if map already has the value for number n 
        if (map.find(n) != map.end()) {
            return map[n];
        }
        //base case
        if (n == 1) return {1};
        //divide
        //bug: left is odd, so left must be n - n/2; right is even, the last one time 2 would
        //be overflowed and cutted, thus formatting to be 2n's beautiful sequence
        vector<int> left = helper(n - n / 2, map);
        vector<int> right = helper(n / 2, map);
        //conquer
        vector<int> ans(n);
        for (int i = 0; i < left.size(); i++) {
            ans[i] = left[i] * 2 - 1; 
        } 
        for (int j = 0; j < right.size(); j++) {
            //bug: are this two index both j?
            ans[j + left.size()] = right[j] * 2;
        }
        //record
        map[n] = ans;
        return ans;
    }
    //分治部分简便的写法
        vector<int> left = helper(n - n / 2, map);
        vector<int> right = helper(n / 2, map);
        //conquer
        vector<int> ans(n);
        int i = 0;
        for (auto& x : left) {
            ans[i++] = x * 2 - 1; 
        } 
        for (auto& y : right) {
            ans[i++] = y * 2;
        }
};