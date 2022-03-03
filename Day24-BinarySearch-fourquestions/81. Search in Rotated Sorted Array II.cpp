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
//以下是解答之前33题的方法，稍微改动能在这题运用
// Formula: If a sorted array is shifted, if you take the middle, always one side will be sorted. Take the recursion according to that rule.

// 1- take the middle and compare with target, if matches return.
// 2- if middle is bigger than left side, it means left is sorted
// 2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
// 2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
// 3- if middle is less than right side, it means right is sorted
// 3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
// 3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)
    bool search(vector<int>& nums, int target) {
        
    }
};