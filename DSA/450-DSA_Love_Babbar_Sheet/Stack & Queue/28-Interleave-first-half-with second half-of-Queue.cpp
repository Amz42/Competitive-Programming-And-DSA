// Article: https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:
    1. Reverse first half elements of queue.
    2. Push first half elements from queue to stack.
    3. Pick 1 element from top of stack & 1 from front of queue, & push them both in the queue.
*/

void interleaveQueue(queue<int> &q){
    stack<int> s;
    int n = q.size();
    for(int i=0;i<n/2;i++) s.push(q.front()), q.pop();  // pushing first half elements into stack
    for(int i=0;i<n/2;i++) q.push(s.top()), s.pop();    // push stack elements into queue
    for(int i=0;i<n/2;i++) q.push(q.front()), q.pop();  // push first half elements of queue back into it
    for(int i=0;i<n/2;i++) s.push(q.front()), q.pop();  // push first half elements into stack

    // interleaving (pick 1 element from top of stack & 1 from queue front)
    for(int i=0;i<n/2;i++) q.push(s.top()), s.pop(), q.push(q.front()), q.pop();
    return;
}

int main(){
    int n,x; cout<<"Size of Queue:"; cin>>n;
    queue<int> q; cout<<"Enter elements in queue: ";
    for(int i=0;i<n;i++) cin>>x, q.push(x);

    interleaveQueue(q);

    cout<<"Interleaved Queue: ";
    for(int i=0;i<n;i++) cout<<q.front()<<" ", q.pop();
    cout<<endl;
}

/*
Input:
    10
    11 12 13 14 15 16 17 18 19 20
Output:
    11 16 12 17 13 18 14 19 15 20
*/