// Question: https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product1525/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6f7ec0e0c1bb0bae6e8cdea37a8e9f07&pid=702815&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minValue(int a[], int b[], int n){
        sort(a, a+n);
        sort(b, b+n, [&](int &a, int &b){
            return a > b;
        });
        
        long long int answer = 0;
        for(int i=0;i<n;i++)
            answer += (a[i] * b[i]);
        
        return answer;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}  // } Driver Code Ends