#include <unordered_set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {


    }
//暴力解法知道做吗？
//错误1: 超时
//错误2: 超量 overflow i2+j2超过了int存储
//解决overflow的办法：将i和j的type设置为long，这样i2和j2将不会超出他们本身类型的限制
//是i2 + j2将会超出int的限制
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= sqrt(c); i++) {
            for (int j = 0; j <= sqrt(c); j++) {
                if (i ^ 2 + j ^ 2 == c) return true;
            }
        }
        return false;
    }

//不超时的巧解：检查b是否能被开根号后是整数
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int) b)
                return true;
        }
        return false;
    } 
//改进这段代码：double和int相等的情况还是有误差存在的,比如4.000005和4
//c++存小数也是用二进制，“==”的判断是有误差精确度的，
//更严谨的做法如下: 用a2+b2=c来判断
    bool judgeSquareSum(int c) {
        //bug 这里a还是不能设置为int，因为a++之后a2会再超出
        //要么将a设置为long，要么提前设置int m = sqrt（c），然后a<=m
        for (int a = 0; a * a <= c; a++) {
            int b = sqrt(c - a * a); 
            if (a * a + b * b == c)
                return true;
        }
        return false;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
};