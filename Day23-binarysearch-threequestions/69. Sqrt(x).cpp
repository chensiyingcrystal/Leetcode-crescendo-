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
//虽然以下方法能通过，但是用==来比较float和int不好 
    int mySqrt(int x) {
        int low = 0, high = x;
        while (high - low > 1) {
            int half = (low + high) / 2;
            //pow的参数自动会转化为double，因此这里如果改成half * half，需要用定义half的类型是long
            //而如果用pow这里则不需要，但要注意的是这里用float和int相比，用“==”operator是bad idea
            //float用二进制存的值并不准确，用==比较是不可靠的，正确做法是fabs(a - b) <= epsilon来判断
            if (pow(half, 2) == x) return half;
            else if (pow(half, 2) > x) high = half;
            else low = half;
        }
        return pow(high, 2) == x? high : low;
    }
//推荐做法如下： 用half*half，同时设置half为long
    int mySqrt(int x) {
        int low = 0, high = x;
        while (high - low > 1) {
            long half = (low + high) / 2;
            if (half * half == x) return half;
            else if (half * half > x) high = half;
            else low = half;
        }
        return pow(high, 2) == x? high : low;
    }

//推荐做法2如下： 用fabs(a - b) < epsilon判断
    int mySqrt(int x) {
        int low = 0, high = x;
        while (high - low > 1) {
            int half = (low + high) / 2;
            float epsilon = 10e-9;
            if (fabs(pow(half, 2) - (float)x) < epsilon) return half;
            else if (pow(half, 2) > x) high = half;
            else low = half;
        }
        return pow(high, 2) == x? high : low;
    }

};