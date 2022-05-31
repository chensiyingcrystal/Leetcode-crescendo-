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
//第一遍自己写的，冗余
    ListNode* deleteDuplicates(ListNode* head) {
        //traverse the linked list and find if the current node's value is equal to its previous node
        if (head == NULL) return NULL;
        ListNode* prev, *curr = head, *next;
        while (curr != NULL) {
            if (curr == head) {
                prev = curr;
                curr = curr->next;
                continue;
            }
            
            next = curr->next;
            if (curr->val == prev->val) {
                prev->next = next;
                curr->next = NULL;
                curr = next;
            }
            else {
                prev = curr;
                curr = next;
            }
        }
        return head;
    }
//better solution
    ListNode* deleteDuplicates(ListNode* head) {
        //traverse the linked list and find if the current node's value is equal to its previous node
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode*curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};