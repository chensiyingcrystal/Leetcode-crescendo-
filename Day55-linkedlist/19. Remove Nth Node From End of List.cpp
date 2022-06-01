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
//two pass algorithm
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //1. firstly we find the length of the list
        ListNode* curr = head;
        int length = 0;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }
        //2. traverse through the list and find L-n nodes and remove its next node from the list
        //bug: must set dummy node here since we need to consider the special case when we need to remove the first node
        length -= n; //no need of setting a new variable
        ListNode dummy = ListNode();
        ListNode* curr2 = &dummy;
        curr2->next = head;
        while (length > 0) {
            curr2 = curr2->next; //bug: when count is equal to length, curr move to its next node
            length--; //count starts from 1 can solve this but cannot solve removing first node problem
        } // use dummy here is the best solution
        curr2->next = curr2->next->next;
        return dummy.next;
    }
//one pass algorithm
//still two pointers trick: let two pointers have n nodes apart
//still set dummy here to handle some special cases
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode* first = &dummy, *second = &dummy;

        //first let second pointer jump to the point that is n nodes apart from the first pointer
        while (n + 1 > 0) {
            second = second->next;
            n--;
        }
        //then move first and second pointers one by one until the second pointer reaches the null
        while (second != NULL) {
            first = first->next;
            second = second->next;
        }
        //let the node to which the first pointer points point to its next next node
        first->next = first->next->next;
        return dummy.next;
    }
};