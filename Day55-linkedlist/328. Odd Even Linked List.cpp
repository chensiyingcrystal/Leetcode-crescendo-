#include <vector>
#include <unordered_set>
#include <stack>
#include <string>
#include <queue>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        int i = 1; 
        ListNode odd_dummy = ListNode();
        ListNode even_dummy = ListNode();
        ListNode* odd = &odd_dummy, *even = &even_dummy;

        ListNode* curr = head;
        while (curr != NULL) {
            if (i % 2 != 0) { 
                odd->next = curr; 
                odd = odd->next; 
            }
            else {
                even->next = curr;
                even = even->next;
            }
            curr = curr->next; 
            i++; 
        }

        if (odd->next == NULL) even->next = NULL;
        if (even->next == NULL) odd->next = NULL;

        odd->next = even_dummy.next;
        return odd_dummy.next;
    }
};