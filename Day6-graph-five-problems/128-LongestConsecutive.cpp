#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int longestConsecutive(vector<int>& nums) {
        // special case
        const int n = nums.size();
        // 建立标记元素，为了查找方便复制所有元素进入unordered_set, 建立存储结果
        unordered_set<int> checked;
        unordered_set<int> nums_set;
        for(int i = 0; i < n; i++) {
            nums_set.insert(nums[i]);
        }
        int count = 0;
        int ans = 0;
        // 对每个未访问元素都要进行一次bfs（找到由该元素延伸开的链条上所有元素，count为链条节数，即每次能获取的最大长度）
        for(int i = 0; i < n; i++) {
            //  保证每次访问的元素是一条新形成的链条，这样做可以减少时间复杂度，避免重复找相同的链条
            // 这也是为什么要对该元素的每个邻居都要进行左右查找，如果只是单方向进行相当于默认递增，而只有找到最小值的时候，链条长度才为最长，元素重复查找导致时间复杂度增加 
            if (!checked.count(nums[i])) {
                //初始化队列
                queue<int> q;
                q.push(nums[i]);
                //计数器工作，同时标记为已访问
                count = 1;
                checked.insert(nums[i]);
                //开始bfs
                while(!q.empty()) {
                    //取出元素并删除
                    int tmp = q.front();
                    q.pop();
                    //邻居满足一定条件时，加入队列并且标记
                    if (nums_set.find(tmp + 1) != nums_set.end() && !checked.count(tmp + 1)) {
                        q.push(tmp + 1);
                        checked.insert(tmp + 1);
                        count += 1;
                    }
                    if (nums_set.find(tmp -1) != nums_set.end() && !checked.count(tmp - 1)) {
                        q.push(tmp - 1);
                        checked.insert(tmp - 1);
                        count += 1;
                    }
                }
                // bfs结束时，说明该链条已经形成尽，将该链条长度更新入ans
                ans = max(count, ans);
            }
        }
        return ans;
    }

//Solution2: 另一种解法是单向增长，所以只找最小值进行最大值的循环，如果有比该元素更小的则跳过，时间复杂度与上面相近
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> x;
        int count=0, ans=0;
        for(int i=0; i<nums.size(); i++) 
            x.insert(nums[i]);
        for(auto i: x) {
            count=0;
            if(!x.count(i-1)) {
                count++;
                 while(x.count(i+1)) {
                    count++;
                     i++;
                 }
                 ans = max(ans, count);
            }
        }
     return ans;
    }
};

int main() {
    return 0;
}