// Question: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4b0de7bb26eb3c7bd548161d5ae4c7f2&pid=700698&user=amanguptarkg6

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    int N;
    void fun(stack<int>& s, int i){
        int e = s.top(); s.pop();
        if(i==N/2) return;
        fun(s, i+1);
        s.push(e);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int n){
        N = n;
        fun(s,0);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends