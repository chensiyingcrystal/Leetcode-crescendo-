#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    Solution() {

    }
    
    int findRedundancyGroup(string s) {
        vector<int> visited(26, 0);
        int n = s.length(), left = 0, right = 0;
        int count = 0;
        bool flag = false;
        while (right < n) {
            int index = s[right] - 'a';
            visited[index]++;

            while (visited[index] > 1) {
                flag = true;
                int i = s[left] - 'a';
                visited[i]--;
                left++;
            }

            if (flag) {
                count++;
                flag = false;
            }
            right++;
        }
        return count + 1;

    }


};

int main() {
    Solution* ss = new Solution();
    string s = "aabcdea";
    int middleMax = ss->findRedundancyGroup(s);
    cout << middleMax << endl;
    
    return 0;
}