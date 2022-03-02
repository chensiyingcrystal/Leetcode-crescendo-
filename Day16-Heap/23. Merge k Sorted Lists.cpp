#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>

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

//Solution1: 在想不出最佳解法下的暴力解法：brute force
//time: o(NlogN), N is the total number of nodes
//space: o(N), sorting cost o(N) space, creating a new linked list cost o(N) space
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //traversing through the lists and record the value of node
        vector<int> new_lists;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* tmp = lists[i];
            while (tmp != nullptr) {
                new_lists.push_back(tmp -> val);
                tmp = tmp -> next;
            }
        }
        
        //consider special case here, for example: lists = [[], []]
        if (new_lists.empty()) return {};

        //sort the new lists in non-decreasing order and make a new linked-lists based on that
        sort(new_lists.begin(), new_lists.end());
        ListNode* head = new ListNode(new_lists[0]);
        ListNode* prev = head;
        for (int i = 1; i < new_lists.size(); i++) {
            ListNode* curr = new ListNode(new_lists[i]);
            prev -> next = curr;
            prev = curr;
        }

        return head;
    }

//Sotion2: merge two lists once, total merging time (k - 1)

//Best Solution: prioritey queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //construct priority queue
        auto compare = [](ListNode* a, ListNode* b) {
            //bug: 是大于不是小于
            return a -> val > b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        //push node into pq
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        //set the head node
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        
        //extract each node from the pq and push next into it
        while (!pq.empty()) {
            tmp -> next = pq.top();
            tmp = pq.top();
            pq.pop();
            if (tmp -> next != nullptr) {
                pq.push(tmp -> next);
            }
        }

        return head -> next;
    }
};