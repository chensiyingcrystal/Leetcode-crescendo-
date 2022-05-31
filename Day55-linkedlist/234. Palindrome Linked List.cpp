#include <vector>
#include <unordered_set>
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
    bool isPalindrome(ListNode* head) {
        //1. traverse through the list and record the value of each node
        string s = "";
        ListNode* curr = head;
        while (curr != NULL) {
            s += to_string(curr->val);
            curr = curr->next;
        }

        //2. determin if the value string can compose of palindrome or not
        int start = 0, end = s.length() - 1;
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
//o(1) space complexity solution
    bool isPalindrome(ListNode* head) {
        //1. find the middle node using fast and slow pointers technique
        


        //2. reverse the half of the list


        //3. compare the two halves of the list to determine if it's a palindrome
    }
};