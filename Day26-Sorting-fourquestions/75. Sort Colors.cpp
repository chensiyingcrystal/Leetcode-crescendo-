#include <vector>
#include <unordered_map>
#include <priority_queue>

using namespace std;

class Solution {
public:
//best solution: two pointers: one for the rightmost boundary of 0, one for the leftmost boundary of 2
    void sortColors(vector<int>& nums) {
        int p0 = 0, curr = 0, p2 = nums.size() - 1;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[p0++]);
            }
            else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2--]);
            }
            else {
                curr++;
            }
        }
    }
//solution1: quicksort, not one-pass
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int first = l, last = r, pivot = nums[first];
        while (first < last) {
            while (first < last && nums[last] >= pivot) {
                last--;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= pivot) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = pivot;
        quickSort(nums, l, first);
        quickSort(nums, first + 1, r);
    }
//solution2: priority queue: not one-pass
    void sortColors(vector<int>& nums) {
        auto comp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);
        for (int& num : nums) {
            q.push(num);
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = q.top();
            q.pop();
        }
    }
};