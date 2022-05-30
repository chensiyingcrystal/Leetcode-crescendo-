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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //bug: ListNode* head = &ListNode();
        //not allowed to initialize like that, since the address of which will be lost as soon as the function ended
        //must initialize a new local node here and then set its pointer
        ListNode node = ListNode();
        ListNode* head = &node;
        ListNode* prev = head, *curr1 = list1, *curr2 = list2;
        
        while (curr1 != NULL && curr2 != NULL) {
            if (curr1 -> val <= curr2 -> val) {
                prev -> next = curr1;
                //bug: must increment prev node!!
                prev = curr1;
                curr1 = curr1 -> next;
            }
            else {
                prev -> next = curr2;
                prev = curr2;
                curr2 = curr2 -> next;
            }
        }
        
        while (curr1 != NULL) {
            prev -> next = curr1;
            prev = curr1;
            curr1 = curr1 -> next;
        }
        
        while (curr2 != NULL) {
            prev -> next = curr2;
            prev = curr2;
            curr2 = curr2 -> next;
        }
        
        return head -> next;
    }
};