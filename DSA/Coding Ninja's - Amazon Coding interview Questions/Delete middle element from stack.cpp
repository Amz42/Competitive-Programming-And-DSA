// Question: https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246

#include<bits/stdc++.h>
using namespace std;

int N;
void fun(stack<int>& s, int i){
    int e = s.top(); s.pop();
    if(i==N/2) return;
    fun(s, i+1);
    s.push(e);
}
void deleteMiddle(stack<int>&inputStack, int n){
	N = n;
    fun(inputStack, 0);
}

int main(){
  return 0;
}