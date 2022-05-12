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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //initialize a pq
        auto comp = [](ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);


       
   }
};