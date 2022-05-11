#include <bits/stdc++.h>

using namespace std;

//initialize the struct type of the elements in the pq
struct item {
    int value;
    int priority;
}

//store the element of a priority queue
item pq[100000];

//set the pointer to the starting position
int curr = 0;

//function to insert a new element into pq
void enqueue(int value, int priority) {
    //insert the element
    pq[curr].value = value;
    pq[curr].priority = priority;
    //increment the pointer
    curr++;
}