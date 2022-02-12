#include <iostream>
#include <vector>
#include <queue>;

using namespace std;

class Solution {
public:
   Solution() {


   }

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty() || (lists.size() == 1 && lists[0] == NULL)) return NULL;
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);
        for(ListNode* listnode : lists) {
            ListNode* temp_node = listnode;
            while (temp_node != NULL) {
                min_heap.push(temp_node);
                temp_node = temp_node->next;
                
            }
        }
        if (min_heap.empty()) 
            return NULL;
        ListNode* mergedlist = min_heap.top();
        ListNode* head = mergedlist;
        min_heap.pop();
        cout << head->val << endl;
        while(!min_heap.empty()) {
            mergedlist->next = min_heap.top();
            mergedlist = min_heap.top();
            min_heap.pop();
        }
        mergedlist->next = NULL;
        return head; 
    }


};


int main() {
    return 0;
}