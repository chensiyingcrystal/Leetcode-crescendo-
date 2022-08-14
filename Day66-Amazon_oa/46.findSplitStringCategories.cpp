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


    int findSplitStringCategories(string categories, int k) {
        //initialize two vectors to read left and right characters
        vector<int> left(26, 0);
        vector<int> right(26, 0);
        int count = 0;
        //loop through the categories and add all characters into right vector
        for (char& c : categories) {
            right[c - 'a']++; //a:2 b:2 c:2
        }
        //loop through categories to find distinct characters matching
        for(int i = 0; i < categories.length() - 1; i++) {
            int x = categories[i] - 'a';//c
            left[x]++;//a:2 b:2 c:2
            right[x]--;//a:0 b:0 c:0
            int match = findCharacterMatch(left, right);//1
            if (match > k) count++;//count: 2
        }
        return count;

    }

    int findCharacterMatch(vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] > 0 && right[i] > 0) ans++;
        }
        return ans;
    }

    

};

int main() {
    Solution* ss = new Solution();
    string s = "adbccdbada";
    int pos = ss->findSplitStringCategories(s, 2);
    cout << pos << endl;
    return 0;


}