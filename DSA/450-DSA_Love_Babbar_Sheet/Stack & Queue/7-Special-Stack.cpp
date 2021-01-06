// Question: https://practice.geeksforgeeks.org/problems/special-stack/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a606d2aba9491cd6a394d3ecb1ce91c4&pid=700453&user=amanguptarkg6

#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}

/*Complete the function(s) below*/

void push(stack<int> &s,int a){
    if(isEmpty(s) || s.top()>a){ 
        s.push(a);
    }else{
        int x = s.top(); s.pop();
        s.push(a); s.push(x);
    }
}

bool isFull(stack<int> &s,int n){
    return s.size()==n ? true : false;
}

bool isEmpty(stack<int> &s){
    return s.empty();
}

int pop(stack<int> &s){
    int x = s.top(); s.pop();
    return x;
}

int getMin(stack<int> &s){
   return s.top();
}