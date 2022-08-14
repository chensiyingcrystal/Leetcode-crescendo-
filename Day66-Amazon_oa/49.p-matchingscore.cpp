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


    int getPmatchingScore(string username1, string username2, int p) {
        int ans = 0;
        //count character's frequency in username2
        unordered_map<char, int> need;
        for (char& c : username2) {
            need[c]++;
        }//a:2 c:1
        //loop through all possible start postition and get its arrange total count
        for (int i = 0; i < p; i++) {//p->2
            int res = findRearrangeCount(username1, username2, need, i, p);
            ans += res;
        }
        return ans;
    }

    int findRearrangeCount(string& username1, string& username2, unordered_map<char, int>& need, int& start, int& p) {
        //initialze a map and counter to record characters frequency in username1
        unordered_map<char, int> has;
        int counter = 0;
        int ans = 0, n = username1.length(), m = username2.length();//m-> 3
        int left = start, right = start;//left->0, start->0

        while (right < n) {//username1-> acaccaa right->6
            char curr = username1[right];//curr->a
            has[curr]++;//a:2 c:1
            if(need.count(curr) && has[curr] == need[curr]) counter++;//counter->2

            while (left < n && counter == need.size()) {
                int len = (right - left + 1) / p + 1;
                if ((right - left + 1) / p + 1 == m) {//3 == m
                    ans++;//ans->1
                }
                char past = username1[left];//past->a
                has[past]--;//a:1 c:1
                if (need.count(past) && has[past] == need[past] - 1) counter--;//counter->1
                left += p;//left->2
            }

            right += p;//right->6
        }

        return ans;
    }

    

};

int main() {
    Solution* ss = new Solution();
    string u1 = "acaccaa", u2 = "aac";
    int pos = ss->getPmatchingScore(u1, u2, 2);
    cout << pos << endl;
    return 0;


}