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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode* currA = headA;
        while (currA != NULL) {
            visited.insert(currA);
            currA = currA->next;
        }

        ListNode* currB = headB;
        while (currB != NULL) {
            if (visited.find(currB) != visited.end()) {
                return currB;
            }
            currB = currB->next;
        }

        return NULL;
    }
};