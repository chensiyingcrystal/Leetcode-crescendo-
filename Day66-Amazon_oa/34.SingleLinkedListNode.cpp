#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
    string name;
    Node* next;

    Node(string name, Node* next) {
        this->name = name;
        this->next = next;
    }


};

class Solution {
public:
    Solution() {

    }
    
    Node* new_head;
    Node* new_tail;
    Node* getShoppingCart(Node* head, vector<vector<string> > operations) {
        new_head = head;
        while (head != NULL && head->next != NULL) {
            head = head->next;
        }
        new_tail = head;

        for (vector<string>& operation : operations) {
            if (operation[0] == "PUSH_HEAD") {
                pushHead(operation[1]);
            }
            else if (operation[0] == "PUSH_TAIL") {
                pushTail(operation[1]);
            }
            else if (operation[0] == "POP_HEAD") {
                popHead(operation[1]);
            }
        }
        return new_head;
    }

    void pushHead(string& name) {
        Node* new_node = new Node(name, NULL);
        if (new_head == NULL && new_tail == NULL) {
            new_head = new_node;
            new_tail = new_node;
        }
        else {
            new_node->next = new_head;
            new_head = new_node;
        }
        return;
    }

    void pushTail(string& name) {
        Node* new_node = new Node(name, NULL);
        if (new_head == NULL && new_tail == NULL) {
            new_head = new_node;
            new_tail = new_node;
        }
        else {
            new_tail->next = new_node;
            new_tail = new_node;
        }
        return;
    }

    void popHead(string& name) {
        Node* temp = new_head->next;
        new_head->next = NULL;
        new_head = temp;
        return;
    }


};

int main() {
    Solution* ss = new Solution();
    Node* node1 = new Node("pen", NULL);
    Node* node2 = new Node("cup", NULL);
    node1->next = node2;
    vector<vector<string> > operations = {{"PUSH_TAIL", "fan"}, {"PUSH_HEAD", "jam"}, 
                {"POP_HEAD", "pen"}, {"POP_HEAD", "pen"}};
    
    Node* ans = ss->getShoppingCart(node1, operations);
    Node* curr = ans;
    while (curr != NULL) {
        cout << curr->name << endl;
        curr = curr->next;
    }
    return 0;
}