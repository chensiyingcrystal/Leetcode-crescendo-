#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        //set two pointers pointing at the end of two strings
        int p1 = num1.length() - 1, p2 = num2.length() - 1;
        //set our point for each round and result string;
        int point = 0;
        string result = "";
        //begin looping
        while (p1 >= 0 && p2 >= 0) {
            //adding two number p1 and p2 pointing to and add point to it
            int tmp = (num1[p1] - '0') + (num2[p2] - '0') + point;
            //setting tmp's last number as the string's end character
            result = to_string(tmp % 10) + result;
            //setting tmp's first number as point for next turn;
            point = tmp / 10;
            //incrementing p1 and p2;
            p1--;
            p2--;
        }
        //bug: use p1--
        while (p1 >= 0) {
            //char to int !! (int)char would convert to ascii number
            //int to char: char c = '0' + i
            int tmp = (num1[p1] - '0') + point;
            result = to_string(tmp % 10) + result;
            point = tmp / 10;
            p1--;
        }

        while (p2 >= 0) {
            int tmp = (num2[p2] - '0') + point;
            result = to_string(tmp % 10) + result;
            point = tmp / 10;
            p2--;
        }
        //bug: forget to add the left point
        if (point > 0) result = to_string(point) + result;
        
        return result;
    }

};