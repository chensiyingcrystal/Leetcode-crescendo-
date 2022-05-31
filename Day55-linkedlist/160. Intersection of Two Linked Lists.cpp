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
//better solution: imagine two animals running and for a period of time, 
//if they are traveling at the same speed, then they must meet with each other
//at the point where they have traveling same length.
//two pointers and math to solve lots of linked list problems
//In the case lists do not intersect, pA and pB will travel m+n length of nodes
//and then both reach the end which is null, then the loop should terminate
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA? pA->next : headB;
            pB = pB? pB->next : headA;
        }
        return pA;
    }
};