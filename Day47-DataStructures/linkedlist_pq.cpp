#include <iostream>

using namespace std;

/** Using linked list to implement priority queue */
// time complexity: enqueue o(1); dequeue o(n); peek o(n)

typedef struct node {
    int data;
    int priority;

    struct node* next;

}Node;