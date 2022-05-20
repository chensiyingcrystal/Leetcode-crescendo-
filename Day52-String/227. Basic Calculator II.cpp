#include <vector>
#include <unordered_map>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int left = 0, right = s.length() - 1;
        return helper(s, left, right);
    }

    int helper(string s, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                int left_result = helper(s, left, i - 1);
                int right_result = helper(s, i + 1, right);
                switch(s[i]) {
                    case('+'):
                        return left_result + right_result;
                    case('-'):
                        return left_result - right_result;
                    case('*'):
                        return left_result * right_result;
                    case('/'):
                        return left_result / right_result;
                }
            }
        }

        while (left <= right && (s[left] == ' ' || s[right] == ' ')) {
            if (s[left] == ' ') left++;
            if (s[right] == ' ') right--;
        }

        return stoi(s.substr(left, right - left + 1));
    }


};

int main() {
    
}