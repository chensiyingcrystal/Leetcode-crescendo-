#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
   Solution() {


   }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    void reorderList(ListNode* head) {
        if (head == NULL) return;
        // find middle 
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // split and reverse the second part
        // important!!! completely split, avoid cycling
        // 两部分需要完全断开，长端在前
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* next;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // merge two part
        ListNode* first = head;
        ListNode* second = prev;
       
        ListNode* tmp;
        // important decision!!!
        // 以短端作为约束条件
        while(second != NULL) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};


int main() {
    return 0;
}