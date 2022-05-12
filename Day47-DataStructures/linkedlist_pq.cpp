#include <iostream>
#include <cstdlib>

using namespace std;

/** Using linked list to implement priority queue */
// time complexity: enqueue o(1); dequeue o(n); peek o(n)

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

//function to push according to priority
