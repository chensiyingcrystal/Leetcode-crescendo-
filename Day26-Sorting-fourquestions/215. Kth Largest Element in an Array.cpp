#include <vector>
#include <list>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return a > b;
        });
        return nums[k - 1];
    }

    //priority queue
    //time: nlogk, space:o(k)
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [](int a, int b) {
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(comp)> q(comp);

        for (int& num : nums) {
            q.push(num);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }

    //quick sort
    //time: o(n), space: o(1)
    //平均情况下，总操作数是n + n/2 + n/4 + ... + 1 = 2n
    //最差情况下，总操作数是n + n - 1 + n - 2 + ... + 1 = o(n2)
    //为了pivot每次不取到极端情况，可在主函数最开始加入随机打乱数组的代码
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        const int n = nums.size();
        int l = 0, r = n - 1;
        while (true) {
            int idx = quickSort(nums, l, r);
            if (n - idx == k) {
                return nums[idx];
            }
            else if (n - idx > k) {
                l = idx + 1;
            }
            else {
                r = idx - 1;
            }
        }
    }

    int quickSort(vector<int>& nums, int l, int r) {
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= pivot) {
                r--;
            }
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) {
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

};