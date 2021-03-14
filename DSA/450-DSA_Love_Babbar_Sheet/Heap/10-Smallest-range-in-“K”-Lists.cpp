// Question: https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f706fa823ef6e82f0b0626f71a1249bf&pid=700497&user=amanguptarkg6

#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

// } Driver Code Ends


// you are required to complete this function 
// function should print the required range
#include <queue>
typedef pair<int , pair<int ,int> > pipii;

struct compare{
    bool operator()(pipii &a, pipii&b){
        return a.first > b.first;
    }
};

pair<int,int> findSmallestRange(int arr[][N], int n, int k){
    int l, r, range = INT_MAX;
    int MaxElement = INT_MIN;
    
    priority_queue<pipii, vector<pipii>, compare> q;
    for(int i=0;i<k;i++){
        q.push({
            arr[i][0],
            {i, 0}
        });
        MaxElement = max(MaxElement, arr[i][0]);
    }
    
    while(q.size()==k){
        auto g = q.top(); q.pop();
        int e = g.first;
        int i = g.second.first;
        int j = g.second.second;
        
        if(MaxElement-e < range){
            range = MaxElement - e;
            l = e;
            r = MaxElement;
        }
        
        // adding next element if it exists
        if(j+1<n){
            MaxElement = max(MaxElement, arr[i][j+1]);
            q.push({
               arr[i][j+1],
               {i, j+1}
            });
        }
    }

    return make_pair(l,r);
}