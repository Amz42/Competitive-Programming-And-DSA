// Question: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Solution 1: https://practice.geeksforgeeks.org/viewSol.php?subId=ef8a72a150e3ca2d48e3e0408c5d60fc&pid=700649&user=amanguptarkg6
// Soltuion 2: https://practice.geeksforgeeks.org/viewSol.php?subId=4b58a506415c354a02a9e806874992de&pid=700649&user=amanguptarkg6



//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;cin>>t;while(t-->0){
        int n,k; cin>>n>>k;
        queue<int> q;
        while(n-->0){ int a; cin>>a, q.push(a);}
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){int a=ans.front(); ans.pop(), cout<<a<<" ";}
        cout<<endl;
    }
}



// Solution 1 // Using Stack & Iteration----------------------------------------------------------
queue<int> modifyQueue(queue<int> q, int k){
    //add code here.
    stack<int> st;
    for(int i=0;i<k;i++) st.push(q.front()), q.pop();
    for(int i=0;i<k;i++) q.push(st.top()), st.pop();
    for(int i=0;i<(int)(q.size()-k);i++) q.push(q.front()), q.pop();   
    return q;
}



// Solution 2 // Using Recursion------------------------------------------------------------------
void reverseKElementsOfQueue(queue<int> &q, int k){
    int e = q.front(); q.pop(); k--;
    if(k) reverseKElementsOfQueue(q,k);
    q.push(e);
}

queue<int> modifyQueue(queue<int> q, int k){
    //add code here.
    reverseKElementsOfQueue(q,k);
    for(int i=0;i<(int)(q.size()-k);i++) q.push(q.front()), q.pop();
    return q;
}