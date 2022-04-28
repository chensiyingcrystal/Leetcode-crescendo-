#include <vector>
#include <unordered_map>
#include <string>

using namespace std;



class Solution {
public:
//进制转换类型的题，通常是利用除法和取模(mod)来进行计算，同时也要注意一些细节:
//如 负数和零。如果输出是数字类型而非字符串，则也需要考虑是否会超出整数上下界。
//recursively:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        if (num > 0) return helper(num);
        return "-" + helper(num * -1);
        
    }

    string helper(int num) {
        if (num < 7) {
            return to_string(num % 7);
        }

        return helper(num / 7) + to_string(num % 7);
    }
//iteratively
    string convertToBase7(int num) {
        if (num == 0) return "0";
        //naming variable: readability
        bool is_negative = false;
        if (num < 0) {
            is_negative = true;
            num = -num;
        }
        string ans = "";
        while (num) {
            int a = num / 7, b  = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        return is_negative? "-" + ans : ans;
    }
};
