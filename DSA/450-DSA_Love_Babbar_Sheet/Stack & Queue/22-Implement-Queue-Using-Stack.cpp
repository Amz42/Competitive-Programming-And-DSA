// Question: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
// Soltuion: https://practice.geeksforgeeks.org/viewSol.php?subId=bf2ddf10135c00e9b9f8deef21bd0be8&pid=700195&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();
};

int main(){
    int T; cin>>T; while(T--){
        StackQueue *sq = new StackQueue();
        int Q; cin>>Q; while(Q--){
            int QueryType=0; cin>>QueryType;
            if(QueryType==1){ int a; cin>>a, sq->push(a);}
            else if(QueryType==2) cout<<sq->pop()<<" ";
        }
        cout<<endl;
    }
}

/* The method push to push element into the queue */
void StackQueue :: push(int x){
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop(){
    if(s1.empty()) return -1;
    while(!s1.empty()) s2.push(s1.top()) , s1.pop();
    int answer = s2.top(); s2.pop();
    while(!s2.empty()) s1.push(s2.top()), s2.pop();
    return answer;
}