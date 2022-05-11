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

//function to check the top element
int peek() {
    item tmp;
    tmp.value = INT_MIN;
    tmp.priority = INT_MIN;

    for (int i = 0; i < curr; i++) {
        if (pq[i].priority == tmp.priority) {
            if (pq[i].value > tmp.value) { 
                tmp = pq[i];
        }
        else if (pq[i].priority > tmp.priority) {
            tmp = pq[i];
            top_index = i;
        }
    }

    return tmp.value;
}

//function to remove element with the highest priority
void dequeue() {
    //find the index of the element with the highest priority or maximum value
    item tmp;
    tmp.value = INT_MIN;
    tmp.priority = INT_MIN;
    int index_tmp = -1;

    for (int i = 0; i < curr; i++) {
        if(pq[i].priority > tmp.priority) {
            tmp = pq[i];
            index_tmp = i;
        }
        else if (pq[i].priority == tmp.priority) {
            if (pq[i].value > tmp.value) {
                tmp = pq[i];
                index_tmp = i;
            }
        }
    }

    //from index tmp to the end of the array, move elements one index ahead
    for (int i = index_tmp; i < curr; i++) {
        pq[i] = pq[i + 1];
    }

    //move the pointer left by one
    curr--;
}

int main() {
    // Function Call to insert elements
    // as per the priority
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
 
    // Check the top element
    cout << peek() << endl;
 
    // Dequeue the top element
    dequeue();
 
    // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
   
      // Dequeue the top element
    dequeue();
   
      // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
 
    return 0;
}