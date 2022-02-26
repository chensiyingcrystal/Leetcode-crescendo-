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
//自己最初写的代码(已修改为正确，标记了出现的错误)
    ListNode *detectCycle(ListNode *head) {
        //bug：这里slow前面也要加*
        ListNode* fast = head, *slow = head;
        //bug:c++中的NULL是大写
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        //这里的判断语句不能放前面，要先do再判断这个，因此用do while语句更合适
        //不是所有的break语句都先放前面
            if (fast == slow) break;
        }
        
        //这里直接判断是不是null就好了，而不是用fast和slow去进行反判断，要学会举反例
        //反例：根本就没有进while循环的情况
        if (fast == NULL || fast -> next == NULL) return NULL;

        fast = head;
        //这行代码其实多余
        if (fast == slow) return head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
//优化的代码：
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        do {
            //这个判别条件就要先放前面，不然后面没法进行
            if (fast == NULL || fast -> next == NULL) return NULL;
            fast = fast -> next -> next;
            slow = slow -> next;
        } while (fast != slow); //bug: while语句后加分号

        fast = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
//这道题要用hash table也能做出，而且是比较直觉的想法，就是代码好不好写呢
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* node = head;
        while (node != NULL) {
            if (visited.find(node) != visited.end()) return node;
            visited.insert(node);
            node = node -> next;
        }
        return NULL;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            )
};