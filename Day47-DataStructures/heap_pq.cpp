#include <vector>
#include <iostream>

using namespace std;

//what is a heap?
//heap is completed binary tree that 
//its root value is always greater or less than it children
//This property is extended to all its children inside it

//In practical, we often use array instead of tree data structures(using pointers)
//to implement a heap.
//Because a heap is a completed binary tree, so when represented by an array,
//for the node at index i, its parent node's index must be i/2;
//and its two children node's indices must be 2i

//Basic implementation in a maximum heap
//float and sink
//float: swap a node with its parent if its value is greater than that of its parent
//keep doing so until its value is less than its new parent's value
//sink: swap a node with its children node(compare with the greater one) if its value is 
//less than its children node; keep doing so unless its value is greater than its children's value

//time complexity
//top: o(1)
vector<int> heap;

//get the top node of the heap, which holds the maximum value among all nodes
int top() {
    return heap[0];
}

//insert new node into the heap: once we insert it into the array, we'll do the float
void push(int k) {
    heap.push_back(k);
    swim(heap.size() - 1);
}

//delete the maximum number; remove the last number to the beginning; and then do the sink



void swim(int pos) {
    while (pos > 0 && heap[pos] > heap[(pos - 1)/2]) {
        swap(heap[pos], heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}



