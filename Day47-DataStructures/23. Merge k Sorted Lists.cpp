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
//another method: if we merge the linkied lists one by one just like we did in merging two linked list
//time complexity should be: N/k * 2 + N/k * 3 + .. + N/k * k = (2+k)(k-1)/2 * N = o(kN)
//introduce a more efficienty algorithm: Divide and Conquer
//time complexity: Nlogk
//merge two sorted linked list together, on each level, we cost o(N)
//we divide lists at most logk times, we have k levels; so the total is Nlogk
//space: o(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return helper(lists, 0, lists.size() - 1);
   }

   ListNode* helper(vector<ListNode*>& lists, int start, int end) {
       if (start == end) {
           return lists[start];
       }
       else {
           int half = (start + end) / 2;
           ListNode* left = helper(lists, start, half);
           ListNode* right = helper(lists, half + 1, end);
           return mergeTwoLists(left, right);
       }
   }

   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if (l1 == NULL && l2 == NULL) return NULL;
       if (l1 == NULL) return l2;
       if (l2 == NULL) return l1;

       ListNode* head = new ListNode(0);
       ListNode* prev = head;
       ListNode* p1 = l1;
       ListNode* p2 = l2;
       while (p1 != NULL && p2 != NULL) {
           if (p1 -> val <= p2 -> val) {
               prev -> next = p1;
               prev = p1;
               p1 = p1 -> next;
           }
           else {
               prev -> next = p2;
               prev = p2;
               p2 = p2 -> next;
           }
       }

       while (p1 != NULL) {
           prev -> next = p1;
           prev = p1;
           p1 = p1 -> next;
       }

       while (p2 != NULL) {
           prev -> next = p2;
           prev = p2;
           p2 = p2 -> next;
       }

       return head -> next;
   }
};