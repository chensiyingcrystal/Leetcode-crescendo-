# Priority queue & Heap Notes
1. **Question Overview**questions overview
* 
* 

2. Introduction to Heap
**What is Priority Queue**
* It's a data structure that allows you to get the maximum number from a tree using o(1) time
and pop the maximum number or insert any value into the tree using o(logn) time meanwhile
keeping the structures of the tree.

* [**To see another explanation**] (https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)

---------------------------**Priority queue properties**-------------------------

* Every item has a priority associated with it
* The first item removed from a queue has the highest priority 
* The queue is either sorted in ascending order or in descending order;
If sorted in acending order, then the smallest number is on the top of the tree;
*On the other hand, the element with the maximum value in the heap will be removed first
in a priority queue with descending order.

---------------------------**Priority queue implementation**-------------------------
* 1. **Using array**
* see details in: [../Day47-DataStructures/array_pq.cpp]
* time complexity: enqueue O(1); dequeue O(n); peek O(n)

* 2. **Using Linked List**
* see details in: [../Day47-DataStructures/linkedlist_pq.cpp]
* time complexity: peek o(1); push o(n); pop o(1)

* 3. **Using Heap**
* see details in: [../Day47-DataStructures/heap_pq.cpp]
* time complexity: top(o(1)); push o(logn); pop(o(log(n)))

---------------------------**Priority queue in c++**----------------------------------
* default priority: the first element of the queue is the greatest of all elements in the queue
* header file: #include <queue>
* basic implementation: push(), top(), pop(), size()
* initialization: priority_queue<int> pq_name; **By default this is a max_heap(maximum on the top)**

* 1. push one by one: time complexity(nlogn): each push operation takes o(logn)
* 2. using built-in copy constructor of priority_queue: time complexity is o(n)
**method**:
* priority_queue<int> pq(address of the first element, address of the next of the last element);
* priority_queue<int> pq (arr, arr + N), where arr is the array and N is the size of the array.
* priority_queue<int> pq(v.begin(), v.end()), where v is the vector.

* 3. Creat min heap using priority_queue STL: use greater<int> class to define a min heap
```
priority_queue<int, vector<int>, greater<int>>pq;
```
where, vector<int> works as container and greater<int> as comparator class

* 4. using lambda function to define your own comparator for pq
* First define the lambda object:

```
auto comp = [](arg1, arg2) {
    if (arg1 < arg2) {
        return true; // true means need to swap
    }
    else {
        return false; // false means current position is okay and do not need to swap
    }
}
```

* then the priority_queue is declared as:
```
priority_queue<int, vector<int>, decltype(comp)>pq(comp);
```
where comp is an object and need to be passed into decltype function





