#include <unordered_map>
#include <bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    Solution() {


    }
//思路：首先做这道题，要意识到每次出现violation，我可以选择修改两个值
//这时候不要着急定下来，思考应该修改哪一个
//用贪心的想法就是：我要修改哪一个取决于会对后面造成什么样的影响，我的贪心目标是什么
//本题贪心的目标就是尽可能形成true，那么我的修改如果能给后面的数值留下更多空间，我就修改哪个
//不要既定思维，我就是应该修改哪个，这里其实就是题目的贪心考点
//修改的极限取决于题目的条件，我就可以直接修改为那个机值（也就是等于旁边的值）
//不确定修改哪个的时候：就需要加入if语句判断和其前一个值？或者前前值的关系
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (i == 1) {
                if (nums[i] < nums[0]) {
                    nums[0] = nums[i];
                    count++;
                }
            }
            else {
                if (nums[i] < nums[i - 1]) {
                    if (count == 0) {
                        if (nums[i] >= nums[i - 2]) {
                            //这种情况下既能修改i也能修改i-1
                            //然而修改i-1能为后面的数字留增长的空间
                            //修改的机值就是等于i
                            nums[i - 1] = nums[i];
                        }
                        else {
                            //这种情况下只能修改当前值
                            nums[i] = nums[i - 1];
                        }
                        count++;
                    }
                    else return false;
                }
            }
        }
        return true;
    } 
//代码的写法：如何简洁
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            //first we check if there's any violation against non-decreasing order
            if (nums[i] < nums[i - 1]) {
                //then let's see if we use up the count opportunity
                //in this case, there's a quick way to decide the answer
                //we often put this in the beginning so the code will run quicker
                //exclude, truncate
                if (count != 0) return false;
                //then we don't need else clause and we could still continue
                //in case of forgetting this incrementing, we put it before
                count++;
                //then we know that we must modify one value
                //the thing is which one is to be modified
                //don't forget the i == 1 case, since here we have i - 2
                //here, if i == 1, in order to leave more space for the left numbers, we always modify nums[0], which is i - 1 in this case
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                }
                else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    )
};