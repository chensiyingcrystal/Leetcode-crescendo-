#include <iostream>
#include <vector>
#include <queue>;

using namespace std;

class Solution {
public:
   Solution() {


   }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* target = curr;
            for(int i = 0; i < n; i++) {
                curr = curr->next;
            }
            if (curr == NULL) {
                // special case: remove the first one; cannot point NULL to head
                if (target == head) head = target->next;
                else {prev->next = target->next;}
                break;
            }
            else {
                prev = target;
                curr = target->next;
            }
        }
        return head;
    }


};


int main() {
    return 0;
}