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
        ListNode* curr = head, *next, *prev = dumb;

        while (curr != NULL && curr->next != NULL) {
            next = curr->next->next;
            curr->next->next = curr;
            prev->next = curr->next;
            prev = curr;
            curr = next;
        }
        
        if (curr != NULL && curr->next == NULL) prev->next = curr;
        if (curr == NULL) prev->next = NULL;

        return dumb->next;
    }
};