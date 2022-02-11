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
        priority_queue<ListNode*, vector<int>, greater<ListNode* > min_heap;
        for(ListNode* listnode : lists) {
            ListNode* temp_node = listnode;
            while (temp_node != NULL) {
                min_heap.push(temp_node*);
                temp_node = temp_node->next;
            }
        }
        ListNode* mergedlist = min_heap.top();
        min_heap.pop();
        while(!min_heap.empty()) {
            mergedlist->next = min_heap.top()
            mergedlist = min_heap.top();
            min_heap.pop();
        }
        
        
    }


};


int main() {
    return 0;
}