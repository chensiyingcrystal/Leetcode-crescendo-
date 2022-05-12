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
//take advantage of sorted lists
//we only need to push the first item of each lists into the pq
//thus decreasing time complexity from nlogn to nlogk
//space: create new linked list costs o(n) space; pq costs o(k) space;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //initialize a pq
        auto comp = [](ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        //push the first node of each list into pq
        for (ListNode* list : lists) {
            //first check if it's null
            if (list != NULL) {
                pq.push(list);
            }
        }
        
        //bug: must instantiate a new ListNode here
        ListNode* head = new ListNode(0);
        ListNode* prev = head;
        ListNode* curr;
        //find the node with the smallest value and then push its next node into pq
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            prev -> next = curr;
            prev = curr;
            //push curr's next into pq
            if (curr -> next != NULL) {
                pq.push(curr -> next);
            }
        }
        return head -> next;
   }
};