#include <vector>

using namespace std;

/**不同排序算法的实现
 * 1、选择排序
 * 每次遍历选出当前数组的最大值，然后删除并添加到新数组中
 * 接着重复上面步骤，直到数组为空，返回新数组，即为排过序的数组
 */

class Sort {
    int findSmallest(vector<int>& nums) {
        int smallest = INT_MAX;
        int smallest_index;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < smallest) {
                smallest = nums[i];
                smallest_index = i;
            }
        }
        return smallest_index;
    }

    vector<int> selectionSort(vector<int>& nums) {
        
    }
};