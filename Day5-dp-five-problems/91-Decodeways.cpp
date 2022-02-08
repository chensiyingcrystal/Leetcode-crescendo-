#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int numDecodings(string s) {
        unordered_set<string> library;
        for(int x = 1; x <= 26; ++x) { library.insert(to_string(x)); }

        const int n = s.length();
        if(s.empty() || s[0] == '0') { return 0; }
        if(n == 1) return 1; 
        vector<int> methods(n + 1, 0);
        methods[0] = 1;
        methods[1] = 1;

        for(int i = 2; i < n + 1; ++i) {
            string e1;
            e1.push_back(s[i - 1]);
            string e2;
            e2.push_back(s[i - 2]);
            if (library.count(e1)) methods[i] = methods[i - 1];
            if (library.count(e2 + e1)) methods[i] += methods[i - 2];
        }
        return methods[n];
    }


//     //压缩空间，字符变换成整数的方法
//     int numDecodings(string s) {
//         if(s.empty() || s[0] == '0') return 0;
//         if(s.length() == 1) return 1;

//         const int n = s.length();
//         int m1 = 1, m2 = 1;
//         for(int i = 2; i < n + 1; ++i) {
//             int w = 0;
//             if(!isValid(s[i - 1]) && !isValid(s[i - 2], s[i - 1])) { return 0; }
//             if(isValid(s[i - 1])) { w = m2; }
//             if(isValid(s[i - 2], s[i - 1])) { w += m1; }
//             m1 = m2;
//             m2 = w;
//         }
//         return m2;
//     }

// private:
//     bool isValid(char c) { return c != '0'; }
//     bool isValid(char c1, char c2) {
//         int num = (c1 - '0') * 10 + (c2 - '0');
//         return num >= 10 && num <= 26;
//     }
};

int main() {
    string s = "126";
    Solution* ss = new Solution();
    int result = ss->numDecodings(s);
    cout << result << endl;
    return 0;
}