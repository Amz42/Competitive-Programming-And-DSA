// Question: https://practice.geeksforgeeks.org/problems/sort-a-stack/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6ae169c20c2d47f288b75cf3912035d9&pid=700469&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s){
    while (!s.empty()){
        printf("%d ", s.top()); s.pop();
    }
    printf("\n");
}

int main(){
    int t; cin>>t; while(t--){
        SortedStack *ss = new SortedStack();
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int k; cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

void sort_stack(int e,int i,stack<int> &s){
    if(s.size()==i){
        s.push(e);
        return;
    }
    
    int a = s.top(); s.pop();
    if(a<e) swap(a,e);
    sort_stack(e, i, s);
    s.push(a);
}

void SortedStack :: sort(){
    int n = s.size();
    for(int i=0;i<n;i++){
        int e = s.top(); s.pop();
        sort_stack(e, i, s);
    }
}

// APPROACH: By Using Bubble Sort type technique
// In each iteration pick largest element & insert it at the unsorted depth of stack