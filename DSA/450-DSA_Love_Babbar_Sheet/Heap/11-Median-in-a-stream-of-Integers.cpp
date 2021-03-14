// Question: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=295a204a7bae2b064631c8bf06c9072c&pid=701360&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

struct compare{
    bool operator()(int &a, int &b){
        return a>b;
    }
};

class Solution{
    public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    
    // Function to insert heap
    void insertHeap(int &x){
        if(max_heap.size()==0 || x<max_heap.top())
            max_heap.push(x);
        else
            min_heap.push(x);
        balanceHeaps();
    }
    
    // Function to balance heaps
    void balanceHeaps(){
        while(abs(min_heap.size()-max_heap.size())>1){
            if(max_heap.size()>min_heap.size()){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }else{
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    
    // Function to return getMedian
    double getMedian(){
        if(min_heap.size()==max_heap.size()){
            double a = min_heap.top(); //min_heap.pop();
            double b = max_heap.top(); //max_heap.pop();
            
            return (a+b)/2;
        }else{
            double a;
            if(min_heap.size()>max_heap.size()){
                a = min_heap.top();
                //min_heap.pop();
            }else{
                a = max_heap.top();
                //max_heap.pop();
            }
            
            return a;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends