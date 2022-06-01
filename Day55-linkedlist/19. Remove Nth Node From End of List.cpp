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
};