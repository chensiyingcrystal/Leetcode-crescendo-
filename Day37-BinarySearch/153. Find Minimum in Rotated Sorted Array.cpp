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
//本题显然用right-left>1能更好地handle chasm中寻找minimum的题
//因为此时我们不再是寻找一个值，而是找到断层所在区间，即将原区间最后收敛到断层左右再取最小值就可以了
//我们知道旋转数组包含两部分，一部分有序，一部分无序（断层所在），因此每次我们都需要丢弃有序区间
//这样最后就可以逐渐向断层收拢
//本题的两种写法，第一种是将mid与左边相等的情况归入左区间，实质上是左指针向右不断侵吞，
//类比34题，其实是在向右寻找边界即寻找断层的最高值，这种方式的话需要增加对于没有旋转数组的处理
//而另一种是将mid与右边相等的情况归入右区间，实质是右边的阵营不断向左靠拢，最后寻找的是断层的最小值
//这种方式符合题目需求，并且能同时应对单调递增数组（未经旋转）
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        //这种情况能handle nums中只有一个或者两个元素的情况，因此不需特别判定
        // if (n == 1) return nums[0];
        //需要考虑单调递增未经旋转的情况
        if (nums[0] < nums[n - 1]) return nums[0];

        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (mid >= 1 && nums[mid] < nums[mid - 1]) return nums[mid];
            if (nums[mid] >= nums[left]) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }

    int findMin(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = n - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (mid >= 1 && nums[mid] < nums[mid - 1]) return nums[mid];
            //不需要考虑单调递增未经旋转的情况，因为右边界一直向左侵吞
            //关键区别是mid等于极值的时候，是左区间挪动还是右区间挪动
            if (nums[mid] <= nums[right]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};