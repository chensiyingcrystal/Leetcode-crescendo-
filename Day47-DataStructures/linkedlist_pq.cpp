#include <iostream>
#include <cstdlib>

using namespace std;

/** Using linked list to implement priority queue */
// time complexity: peek o(1); push o(n); pop o(1)

typedef struct node {
    int data;
    int priority;

    struct node* next;

}Node;

//function to create a new node

Node* newNode(int d, int p) {
    //The malloc() function in C++ allocates a block of uninitialized memory to a pointer. 
    //It is defined in the cstdlib header file.
    //malloc returns a void pointer to the unitialized memory block allocated by the function
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = d;
    tmp -> priority = p;
    tmp -> next = NULL;

    return tmp;
}

//return the value at head
int peek(Node** head) {
    return (*head) -> data;
}

void pop(Node** head) {
    Node* temp = (*head);
    (*head) = (*head) -> next;
    //In C++, the delete operator should only be used either for the pointers 
    //pointing to the memory allocated using new operator or for a NULL pointer, 
    //and free() should only be used either for the pointers pointing to the memory 
    //allocated using malloc() or for a NULL pointer.
    free(temp);
    // temp -> next = NULL; 
}

//function to push according to priority
void push(Node** head, int d, int p) {
    Node* start = (*head);

    //create a new node
    Node* temp = newNode(d, p);

    //if the start node's priority is less than that of temp
    //we'll set the temp as the start node
    if (start -> priority < temp -> priority) {
        //insert new node before head
        temp -> next = start;
        (*head) = temp;
    }
    else {
        //else we'll need to look for the first node of which the p is less than the temp's
        Node* prev = start;
        Node* curr = start -> next;
        while (curr != NULL && curr -> priority >= temp -> priority) {
            prev = curr;
            curr = curr -> next;
        } 
        prev -> next = temp;
        temp -> next = curr;
    }
}

    //function to check if list is empty
int isEmpty(Node** head) {
    return (*head == NULL);
}

// Driver code
int main()
{
    // Create a Priority Queue
    // 7->4->5->6
    Node* pq = newNode(4, 0);
    push(&pq, 5, 1);
    push(&pq, 6, 2);
    push(&pq, 7, 3);
 
    while (!isEmpty(&pq)) {
        cout << " " << peek(&pq);
        pop(&pq);
    }
    return 0;
}
