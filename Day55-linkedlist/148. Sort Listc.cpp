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
    ListNode* sortList(ListNode* head) {
        //special case
        if (head == NULL) return NULL;
        //base case
        if (head->next == NULL) return head;
        //recursive: divide the list into two halfs; then sort two parts, respectively
        ListNode* second = sortList(breakIntoHalf(head));
        ListNode* first = sortList(head);
        //merge two sorted list together into one sorted list
        return mergeSortedList(first, second);
    }

    ListNode* breakIntoHalf(ListNode* head) {
        //set two pointers, one goes two steps and the other goes one step each time
        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode* slow = &dummy, *fast = &dummy;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = slow->next;
        slow->next = NULL;
        return half;
    }

    ListNode* mergeSortedList(ListNode* first, ListNode* second) {
        //set two pointers, one to the start of the first list, the other for the second list
        //each iteration link the node with the less value to the previous node and update the previous node and one of the pointers
        ListNode dummy = ListNode();
        ListNode* prev = &dummy, *p_first = first, *p_second = second;
        while (p_first != NULL && p_second != NULL) {
            if (p_first->val <= p_second->val) {
                prev->next = p_first;
                prev = p_first;
                p_first = p_first->next;
            }
            else {
                prev->next = p_second;
                prev = p_second;
                p_second = p_second->next;
            }
        }

        while (p_first != NULL) {
            prev->next = p_first;
            prev = p_first;
            p_first = p_first->next;
        }

        while (p_second != NULL) {
            prev->next = p_second;
            prev = p_second;
            p_second = p_second->next;
        }

        return dummy.next;
    }
};