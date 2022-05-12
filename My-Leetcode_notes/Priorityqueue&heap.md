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
* time complexity: