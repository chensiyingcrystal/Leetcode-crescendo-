#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
//想办法：建立存储n个数字是否为质数的数组；对质数的倍数进行修改，剩余的为合数
//可利用质数的性质优化算法
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> res(n);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!res[i]) {
                count++;
                for (int j = 2 * i; j < n; j += i) {
                    if (!res[j]) {
                        res[j] = true;
                    }
                }
            }
        }
        return count;
    }

};
