#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    Solution() {

    }

    int findFinalPosition(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (string& command : commands) {
            if (command == "UP" && i - 1 >= 0) {
                i--;
            }
            else if (command == "DOWN" && i + 1 < n) {
                i++;
            }
            else if (command == "LEFT" && j - 1 >= 0) {
                j--;
            }
            else if (command == "RIGHT" && j + 1 < n) {
                j++;
            }
        }
        return i * n + j;
    }

    

};

int main() {
    Solution* ss = new Solution();
    vector<string> s;
    s.push_back("RIGHT");
    s.push_back("UP");
    s.push_back("DOWN");
    s.push_back("LEFT");
    s.push_back("DOWN");
    s.push_back("DOWN");
    int pos = ss->findFinalPosition(4, s);
    cout << pos << endl;


}