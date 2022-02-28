#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
    //很多时候双指针是一种辅助手段 //双指针的经典应用：连续对应字符
    //这个题之所以可以使用双指针辅助是因为比较字符串是基于顺序推进的，这样一遍就够
    //使用sorting： time： o(nxlogn + nx)(n: dictionary的字符串数量，x是字符串平均长度)； space： o(logn)
    string findLongestWord(string s, vector<string>& dictionary) {
        //bug：sort函数的写法，把想要排在前面的元素放在小于号前面，根据排在前面元素的属性排序
            sort(dictionary.begin(), dictionary.end(), [](string& a, string&b) {
                if (a.length() == b.length()) return a < b;
                else return a.length() > b.length();
            });
            string result = "";
            for (string& dic : dictionary) {
                if (checkWord(s, dic)) {
                    return dic;
                }
            }
            return "";
        } 

    bool checkWord(string& s, string& dic) {
        if (dic.length() > s.length()) return false;
        int p1 = 0, p2 = 0;
        while (p1 < s.length() && p2 < dic.length()) {
            if (s[p1] == dic[p2]) p2++;
            p1++;
        }
        return p2 == dic.length()? true : false;
    }

//不使用sorting的写法: time: o(nx), space: o(x)(字符串的空间分析要按照字符个数)
   string findLongestWord(string s, vector<string>& dictionary) {
            string result = "";
            for (string& dic : dictionary) {
                if (checkWord(s, dic)) {
                    if (dic.length() > result.length() || (dic.length() == result.length() && dic < result)) {
                            result = dic;
                        };
                }
            }
            return result == ""? "" : result;
        } 

    bool checkWord(string& s, string& dic) {
        if (dic.length() > s.length()) return false;
        int p1 = 0, p2 = 0;
        while (p1 < s.length() && p2 < dic.length()) {
            if (s[p1] == dic[p2]) p2++;
            p1++;
        }
        return p2 == dic.length()? true : false;
    }


};