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
        for(int x = 0; x <= 25; ++x) {
            library.insert(to_string(x));
        }

        
        
    }




}

int main() {
    string s = "126";
    Solution* ss = new Solution();
    int result = ss->numDecodings(s);
    cout << result << endl;
    return 0;
}