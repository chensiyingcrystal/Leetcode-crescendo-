#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(nullptr) {};
};

class Solution {
public:
    Solution() {

    }

    ListNode* removeAllIntegers(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy, *temp = head;

        while (temp != nullptr) {
            if (temp->val != n) {
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }

        curr->next = nullptr;
        return dummy->next;


        
    }



};

int main() {
    Solution* ss = new Solution();
    string s = "AB", l = "ABCABCEEABABDSFAB";
    int ans = ss->FindRepetition(s, l);
    cout << ans << endl;
    

    return 0;


}