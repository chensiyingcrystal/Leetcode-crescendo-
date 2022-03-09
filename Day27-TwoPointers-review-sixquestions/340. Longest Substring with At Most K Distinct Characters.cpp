#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
//记录unique character所用数据结构总结：一定要同时记录字符索引和出现的次数
//那么我们可以用：
//1.如果题目中明确提到用小写字母或者大写字母，可以用vector<int>（n）
//这种情况下切记要开辟好空间，然后在判断字符是否出现时可以直接用单一条件就是字符索引下是否等于0来判断
//2.如果题目中未明确提到用哪些字符，应优先用hash map
//这种情况下不用提前开辟空间，但是在判断字符时要注意写两个条件，新加入的用count判断，旧加入的要用等于0去指示
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        //sliding window: use vector list to record unique character
        //由于题目中没有说用的字符范围，所以这里优先用hash map
        unordered_map<char, int> unique;
        int left = 0, right = 0;
        int count = 0, size = INT_MIN;
        while (right < s.length()) {
            //bug：这里有可能存在已经加入的字符变为0的情况
            //！！！不能用count去指示0的变化
            //unique character类型的题：一定要加入降为0的条件作为指示！！
            if (!unique.count(s[right]) || unique[s[right]] == 0) {
                count++;
            }
            unique[s[right]]++;

            while (count > k) {
                unique[s[left]]--;
                if (unique[s[left]] == 0) count--;
                left++;
            }

            if (right - left + 1 > size) {
                size = right - left + 1;
            }

            right++;
        }
        
        return size;
    }    
};