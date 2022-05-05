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
};