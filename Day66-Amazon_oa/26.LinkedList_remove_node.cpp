#include <unordered_set>
#include <unordered_map>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
}


class Solution {
public:
    Solution() {

    }

    int findMaxNodeSum(Node* head) {
        if (head == NULL) return 0;
        //find middle node
        Node* slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //break into two lists and reverse the second one
        Node* tail = slow->next;
        slow->next = NULL;
        Node* prev = NULL, *curr = tail, *next;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = prev;

        //calculate sum of each node from head and tail
        int maxSum = INT_MIN;
        Node* currHead = head, *currTail = tail;
        while (currHead != NULL || currTail != NULL) {
            int h = currHead == NULL? 0 : currHead->val;
            int t = currTail == NULL? 0 : currTail->val;
            maxSum = max(maxSum, h + t);
            currHead = currHead->next;
            currTail = currTail->next;
        }
        
        return maxSum;
    }

    


};