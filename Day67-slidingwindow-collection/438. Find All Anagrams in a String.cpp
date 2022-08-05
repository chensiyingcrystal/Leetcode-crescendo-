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
//最开始的算法
//用map记录，遇到重复字符直接跳过全部
//需要用到map的clear(o(N))
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        int m = s.length(), n = p.length();
        //calculate character frequency in p
        unordered_map<char, int> need;
        for (auto& c : p) {
            need[c]++;
        }
        
        unordered_map<char, int> had;
        int count = 0;
        vector<int> ans;
        int left = 0, right = 0;
        
        while (right < m) {
            char c = s[right];
            if (need.count(c)) {
                had[c]++;
                if (had[c] == need[c]) count++;
            }
            else {//遇到没有出现在t中的字符直接跳过（代替一个个排除）
                right++;
                left = right;
                had.clear(); //所有经过的字符一次性清零
                count = 0; //曾经的计数器清零
                continue;
            }
            //case1: s-->"aba" t-->"ab"
            //case2: s-->"abw" t-->"ab"
            while (had[c] > need[c]) { 
                char x = s[left];
                if (had[x] == need[x]) count--;
                had[x]--;
                left++;
            }
            //套用模板一，全部字符排除后记录有效结果
            if (count == need.size() && right - left + 1 == n) {
                ans.push_back(left);
            }
            
            right++; 
        }
        
        return ans; 
    }

//方法二：将map优化为vector，注意初始大小（虽然s中只有26字母，但是从97-122）
//map clear之后可以直接用，但是vector clear后失去了初始大小
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        if (m < n) return {};
        int left = 0, right = 0;
        vector<int> freq_s(128, 0); //size如果是26，后面的索引也要改为相对的
        vector<int> freq_t(128, 0);     
        for (char& c : p) {
            freq_t[c]++;
        }
        vector<int> ans;
        
        while (right < m) {
            char c = s[right];
            //case1: unecessary characters.  s--> cadec t--> adc 
            if (freq_t[c] == 0) {
                right++;
                left = right;
                vector<int> s2(128, 0); //bug：vector的clear慎用！
                freq_s = s2; //bug：忘记将freqs清零
                continue;
            }
            freq_s[c]++;

            //case2: duplicate characters  s--> adehabc   t--> adehbc
            while(freq_s[c] > freq_t[c]) {
                char c1 = s[left];
                freq_s[c1]--;
                left++;
            }
            
            if (right - left + 1 == n) {
                ans.push_back(left);
            }
            
            right++;
        }
        
        return ans;
    }
//方法三：套用模板2，不对多余字符单独排除处理
//排除多余字符，并且仅在有效时候记录结果
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        if (m < n) return {};
        int left = 0, right = 0;
        vector<int> freq_s(26, 0);
        vector<int> freq_t(26, 0);
        int count = 0, need = 0;
        for (char& c : p) {//注意索引
            if (freq_t[c - 'a'] == 0) need++;
            freq_t[c - 'a']++;
        }
        vector<int> ans;
        
        while (right < m) {
            char c = s[right];
            int ic = c - 'a';
            freq_s[ic]++;
            if (freq_s[ic] == freq_t[ic]) count++;

            while(count == need) {
                if (right - left + 1 == n) {
                    ans.push_back(left);
                }
                char c1 = s[left];
                int ic1 = c1 - 'a';
                if (freq_s[ic1] == freq_t[ic1]) count--;
                freq_s[ic1]--;
                left++;
            }
            
            right++;
        }
        
        return ans;
    }
};