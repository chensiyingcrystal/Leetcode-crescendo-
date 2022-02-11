#include <iostream>
#include <vector>

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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* next_node;
        while(left && right) {
            if (left->val <= right->val) {
                if (left->next != NULL && (left->next)->val <= right->val) left = left->next;
                else {
                    next_node = left->next;
                    left->next = right;
                    left = next_node;
                }
            }
            else {
                if (right->next != NULL && (right->next)->val < left->val) right = right->next;
                else {
                    next_node = right->next;
                    right->next = left;
                    right = next_node;
                }
            }
        }
        if(list1->val <= list2->val) return list1;
        else {return list2;}
    }


};


int main() {
    return 0;
}