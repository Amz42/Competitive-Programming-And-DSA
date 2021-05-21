// Question: https://practice.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=5c3a8fa5b33fbdf111677726ae75aafa&pid=700241&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int n, int m){
        int i = 0, j = 0;
        int a = 0, b = 0;
        int answer = 0;
        
        while(i<n && j<m){
            if(A[i] == B[j]){
                answer += (max(a, b) + A[i]);
                i++, j++;
                a = b = 0;
            }else if(A[i] > B[j]){
                b += B[j++];
            }else
                a += A[i++];
        }
        
        while(i<n) a += A[i++];
        while(j<m) b += B[j++];
        
        answer += max(a,b);
        
        return answer;
    }
};


// 1 2 8 9
// 1 2 3 10

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends