#include <vector>
#include <unordered_map>
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode node = ListNode();
        ListNode* dummy = &node;
        ListNode* curr = head, *next, *prev = dummy;

        while (curr != NULL && curr->next != NULL) {
            //first store the next node that to be processed
            next = curr->next->next;
            //then swap two nodes
            curr->next->next = curr;
            //then let prev node point to the new current node
            prev->next = curr->next;
            //lastly increment previous node and current node
            prev = curr;
            curr = next;
        }
        // //if there are odd number of nodes in the list
        // if (curr != NULL && curr->next == NULL) prev->next = curr;
        // //if there are even number of nodes in the list
        // if (curr == NULL) prev->next = NULL;
        //simplify above lines of codes here below:
        prev->next = curr;
        return dummy->next;
    }
};