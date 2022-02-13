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
// optimized: time complexity: Nlogk, space complexity: k
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // set the item before the head领头羊，下一个就是head
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;

        // construct priority queue
        auto comp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // put items into the queue
        // important: must check if list, incase of [[], [], ...], because NULL has no next nor val
        for(ListNode* list : lists){
            pq.push(list);
        }

        // extract item and put into another
        while(!pq.empty()) {
            head->next = pq.top();
            head = pq.top();
            pq.pop();
            if (head->next) pq.push(head->next);
        }
        return dummy->next;
    }

    

// time complexity: NlogN, space complexity: N
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        // lambda expression
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        // use lambda ass comparator: use decltype and pass it to the template argument and also the constructor
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);
        // NlogN, instead of putting every items into the queue, we can only put every single list
        for(ListNode* listnode : lists) {
            ListNode* temp_node = listnode;
            while (temp_node != NULL) {
                min_heap.push(temp_node);
                temp_node = temp_node->next;
                
            }
        }
        // if initialize like below, then must consider special case before: [[], [], ...]
        if (min_heap.empty()) 
            return NULL;
        // must initialize like below; 
        ListNode* mergedlist = min_heap.top();
        min_heap.top();
        ListNode* head = mergedlist;
        while(!min_heap.empty()) {
            mergedlist->next = min_heap.top();
            mergedlist = min_heap.top();
            min_heap.pop();
        }
        // end the last item
        mergedlist->next = NULL;
        return head; 
    }

//  延伸：
// （1）对于有序的k队列，每个队列元素平均为m
// 全部扔进pq：时间复杂度kmlogkm（需要进行km次操作，每次push或者pop需要logkm）， 空间复杂度km
// 只将k队列扔进pq，每次取出一个最小然后再放入一个元素，保证pq里的元素最大为k：时间复杂度kmlogk， 空间复杂度k
// （2）对于无序的k队列，每个队列元素平均为m
// 全部扔进pq：时间kmlogkm， 空间km
// 先将每个序列用分治法排序，再按k序列扔进去：时间复杂度kmlogm + kmlogk = kmlogkm，空间k
// —————分治法排序一个m长的队列：时间复杂度mlogm，空间m
//      先找到一半的位置（一个人跑一步，另一个人跑两步，当跑两步的人到达终点，跑一步的人到达一半，此操作时间为m）；
//      分成一半，再分成一半，直到分成单个元素，深度是logm；
//      将m长队列分成单个元素需要mlogm的时间；
//      再将单个元素与单个元素进行按照顺序的merge，此操作时间是m（每个元素是1，需要进行m次）
//      将两个排好序的元素与另外排序好的两元素按顺序merge，此操作时间仍是m（每个元素是2，需要进行m/2次）
//      依次进行，每一层的操作数是m，深度是logm，总的仍然是mlogm，因此总操作数是2mlogm，仍然属于mlogm的量级

};


int main() {
    return 0;
}