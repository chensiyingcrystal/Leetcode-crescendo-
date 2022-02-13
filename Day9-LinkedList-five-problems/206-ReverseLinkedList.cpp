#include <iostream>
#include <vector>

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

    ListNode* reverseList(ListNode* head) {
        // special case
        if (head == NULL) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr->next != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        return curr; 
    } 


};


int main() {
    return 0;
}