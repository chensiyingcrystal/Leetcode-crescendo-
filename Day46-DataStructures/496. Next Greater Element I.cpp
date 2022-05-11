#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
// Time complexity: O(n). The entire nums2nums2 array (of size nn) is scanned only once. 
//Each of the stack's nn elements are pushed and popped exactly once. 
//The nums1nums1 array is also scanned only once. 
//All together this requires O(n + n + m)O(n+n+m) time. 
//Since nums1nums1 must be a subset of nums2nums2, 
//we know mm must be less than or equal to nn. 
//Therefore, the time complexity can be simplified to O(n)O(n).

// Space complexity: O(n). mapmap will store nn key-value pairs 
// while stackstack will contain at most nn elements at any given time.
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //store our result
        unordered_map<int, int> firstGreater;
        //initialize a stack of element in nums2;
        stack<int> stk;
        //begin looping through elements in nums2 in reverse order
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }
            firstGreater[nums2[i]] = stk.empty()? -1 : stk.top();
            stk.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = firstGreater[nums1[i]];
        }
        
        return ans;
    }
};