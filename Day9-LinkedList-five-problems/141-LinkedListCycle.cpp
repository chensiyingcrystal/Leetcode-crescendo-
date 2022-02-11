#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
   Solution() {


   }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
// space complexity o(n), time o(n)
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while(curr != NULL) {
            if (visited.find(curr->next) != visited.end()) return true;
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }

// space can be o(1)
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode* curr = head;
        while(curr != NULL) {
            if (curr->val == INT_MIN) return true;
            curr->val = INT_MIN;
            curr = curr->next;
        }
        return false;
    }

};


int main() {
    return 0;
}