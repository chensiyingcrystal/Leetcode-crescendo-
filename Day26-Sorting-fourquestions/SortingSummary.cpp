#include <iostream>
#include <vector>

using namespace std;


class Sort {
public:
    Sort () {

    }
/**不同排序算法的实现
 * 1、选择排序
 * 每次遍历选出当前数组的最大值，然后删除并添加到新数组中
 * 接着重复上面步骤，直到数组为空，返回新数组，即为排过序的数组
 * 
 * 时间复杂度：o(n2)
 */
//选择排序的简单代码
    vector<int> selectionSort(vector<int>& nums) {
        const int n = nums.size();
        int smallest;
        for (int i = 0; i < n - 1; i++) {
            smallest = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[smallest]) {
                    smallest = j;
                }
            }
            swap(nums[i], nums[smallest]);
        }
        return nums;
    }
//选择排序的复杂实现
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

    vector<int> selectionSort2(vector<int>& nums) {
        vector<int> sorted;
        while (!nums.empty()) {
            int curr = findSmallest(nums);
            sorted.push_back(nums[curr]);
            nums.erase(nums.begin() + curr);
        }
        return sorted;
    }

/** 2、快速排序
 * 运用的思想：分而治之D&C
 * 时间复杂度：o(nlogn)
 */
    void quick_sort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return; 
        }
        int first = l, last = r, key = nums[first];
        while (first < last){
        while(first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) {
                ++first; 
            }
        nums[last] = nums[first];
        }
        nums[first] = key;
        quick_sort(nums, l, first);
        quick_sort(nums, first + 1, r);
    }

/**3. 归并排序 merge sort
 * 算法：分而治之
 * 先分一半，再将每个一个继续分成一半，直至到单个元素
 * 然后再merge，先是两两排序merge，再两个和两个数组排序merge（打擂台算法）
 * 时间复杂度： nlogn
 */
//第一种方式：创建全部新的数组进行顺序merge
    void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp) {
        if (l >= r) { return; }
    // divide
        int m = l + (r - l) / 2;
        merge_sort(nums, l, m, temp);
        merge_sort(nums, m + 1, r, temp);
    //conquer
        int p = l, q = m + 1, i = l;
        while (p <= m || q <= r) {
            if (q > r || p <= m && nums[p] <= nums[q]) {
                temp[i++] = nums[p++];
            }
            else {
                temp[i++] = nums[q++];
            }
        }

        for (int i = l; i <= r; i++) {
            nums[i] = temp[i];
        }
    }
//第二种方式：创建后半边数组，在原数组倒序merge

/**4. 冒泡排序 bubble sort
 * 算法：对0到n-1的数组进行遍历，将i位置元素与其相邻元素进行比较，大的往后移动
 * 然后对0到n-2的数组重复此操作，直到元素剩下一个
 * 时间复杂度： n2
 */

/** 5. 插入排序 insert sort
 * 算法：从index为1的数开始（第二个），设定i位置的数为key，对从0至i-1的排好序的数组进行遍历（index为j）
 * 将其插入到合适的位置：while(j > 0 || A[j] > key) A[j + 1] = A[j--]; 退出循环后A[j + 1] = key;
 * 时间复杂度： best case: o(n)(原数组已经排好序); worst case: o(n2)
 */
//更为简便的代码写法 
    void insertion_sort(vector<int> &nums, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
                swap(nums[j], nums[j-1]);
            }
        }
    }

};


int main() {
    Sort* t = new Sort();
    vector<int> nums {2, 1, 3, 5, 4, 8, 9, 6};
    vector<int> temp(8);
    t->merge_sort(nums, 0, 7, temp);
    for (int& element : nums) {
        cout << element << endl;
    }
    return 0;
}
