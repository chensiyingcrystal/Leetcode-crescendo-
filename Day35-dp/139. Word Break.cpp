#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
//典型的需要回看每个开头的dp题
//这里dp[i]表示的是以i元素对应的字符结尾的字符串
//由于开头不明确，所以需要增加一道循环去找对应的开头，以保证不重不漏
//这里注意空间的使用上，只需要n就够了，不要n2，因为dp[i]只与dp[i-1]有关
//只要dp[i]为true，就修改结果为true，其余情况保持默认
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;
        //preprocess the wordDict: change it into a hash_set 
        unordered_set<string> newDict;
        for (string& word : wordDict) {
            newDict.insert(word);
        }
        //initialize a container to record dp result
        const int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= i; l++) {
                if (newDict.find(s.substr(i - l, l)) == newDict.end()) continue;
                dp[i] = dp[i - l];
                if (dp[i]) break;
            }
        }
        return dp[n];
    }             
//另一个写法是，开头与dict里面的字符长度相关,这样就不用逐个字符检查是否与dict中word匹配
//如果以i对应字符结尾，以扣去dict字符长度后开头的字符串与该word相同
//那么dp[i] = dp[i] || dp[i-L]
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;
        //initialize a container to record dp result
        const int n = s.length();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (string& word : wordDict) {
                int length = word.length();
                if (i >= length && s.substr(i - length, length) == word) {
                    dp[i] = dp[i] || dp[i - length];
                }
                if (dp[i]) continue;
            }
        }
        return dp[n];
    }
};