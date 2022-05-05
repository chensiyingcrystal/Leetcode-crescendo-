#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
//using unordered_map
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> count;
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (!count.count(i)) ans.push_back(i);
        }
        return ans;  
    }
//using unordered_set
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> count;
        const int n = nums.size();
        for (auto& num : nums) {
            count.insert(num);
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (count.find(i) == count.end()) ans.push_back(i);
        }
        return ans;  
    }
//也可以利用数字的特性，第一遍将数字指示的index（num-1）的位置的数字变为负数
//第二遍循环检查哪些没有变为负数的，将其index+1丢入ans数组中
};