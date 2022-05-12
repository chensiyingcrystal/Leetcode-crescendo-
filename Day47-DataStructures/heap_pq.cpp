#include <vector>
#include <iostream>

using namespace std;

//what is a heap?
//heap is completed binary tree that 
//its root value is always greater or less than it children
//This property is extended to all it

//A complete binary tree is a binary tree in which all the levels 
//are completely filled except possibly the lowest one, 
//which is filled from the left. 
//A complete binary tree is just like a full binary tree, but with two major differences. 
//All the leaf elements must lean towards the left.

//In practical, we often use array instead of tree data structures(using pointers)
//to implement a heap.
//Because a heap is a completed binary tree, so when represented by an array,
//for the node at index i, its parent node's index must be (i-1)/2;
//and its two children node's indices must be 2i+1 and 2i+2

//Basic implementation in a maximum heap
//float and sink
//float: swap a node with its parent if its value is greater than that of its parent
//keep doing so until its value is less than its new parent's value
//sink: swap a node with its children node(compare with the greater one) if its value is 
//less than its children node; keep doing so unless its value is greater than its children's value

//time complexity
//top: o(1)
class Heap{
public:
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
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        sink(0);
    }


    void swim(int pos) {
        while (pos > 0 && heap[pos] > heap[(pos - 1)/2]) {
            swap(heap[pos], heap[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }

    void sink(int pos) {
        while (2 * pos + 1 < heap.size()) { // we at least want to make sure that its left child is in the boundary
            int j = 2 * pos + 1; //start with its left child
            if (j + 1 < heap.size() && heap[j] < heap[j + 1]) j++; //use pointers!! if right child exists and is greater than the left, then move the pointer to the right
            if (heap[pos] >= heap[j]) break; // if greater than the bigger child, then break
            swap(heap[pos], heap[j]);
            pos = j; // update the pointer
        }
    }    
};


int main() {
    Heap heap;
    heap.push(3);
    heap.push(6);
    heap.push(7);
    heap.push(8);
    cout << heap.top() << endl;
    heap.pop();
    heap.pop();
    cout << heap.top() << endl;
    heap.push(20);
    heap.push(5);
    heap.push(1);
    heap.push(30);
    cout << heap.top() << endl;
}




