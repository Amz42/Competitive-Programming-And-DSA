// Question: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b3fccdf10948fe65cd0e745550ecf2b2&pid=700198&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};

int main(){
    int T; cin>>T; while(T--){
        QueueStack *qs = new QueueStack();
        int Q; cin>>Q; while(Q--){
            int QueryType = 0; cin>>QueryType;
            if(QueryType==1){
                int a; cin>>a;
                qs->push(a);
            }else if(QueryType==2) cout<<qs->pop()<<" ";
        }
        cout<<endl;
    }
}

void QueueStack :: push(int x){
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop(){
    if(q1.empty()) return -1;
    while(q1.size()!=1) q2.push(q1.front()), q1.pop();
    int e = q1.front(); q1.pop();
    while(!q2.empty()) q1.push(q2.front()), q2.pop();
    return e;
}