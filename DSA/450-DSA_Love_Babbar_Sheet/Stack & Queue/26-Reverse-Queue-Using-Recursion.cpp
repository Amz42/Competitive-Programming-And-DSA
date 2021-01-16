// Question: https://practice.geeksforgeeks.org/problems/queue-reversal/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6c571c76aaa6eff08f11cd7b70fddd97&pid=700646&user=amanguptarkg6

//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main(){
    int test; cin>>test; while(test--){
        queue<int> q;
        int n, var; cin>>n;
        while(n--) cin>>var, q.push(var);
        queue<int> a=rev(q);
        while(!a.empty()){
            cout<<a.front()<<" ";
            a.pop();
        }
        cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

void reverseQueue(queue<int> &q){
    int e = q.front(); q.pop();
    if(q.size()) reverseQueue(q);
    q.push(e);
}

queue<int> rev(queue<int> q){
    // add code here.
    reverseQueue(q);
    return q;
}