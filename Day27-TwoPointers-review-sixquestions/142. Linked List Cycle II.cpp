#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:


    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
//solution1
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (visited.count(curr)) return curr;
            visited.insert(curr);
            curr = curr -> next;
        }
        return nullptr;
    }
//solution2
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode* fast = head, *slow = head;
        
        //这里要么用do while语句，要么就要赋初始值，不然没法开始
        if (fast == nullptr || fast -> next == nullptr) return nullptr;
        fast = fast -> next -> next;
        slow = slow -> next;
        
        while (fast != slow && fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        if (fast == nullptr || fast -> next == nullptr) return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
        
};