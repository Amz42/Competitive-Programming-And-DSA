// Question: https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6b95f6d94371ff38d25aeeef70c43f89&pid=700450&user=amanguptarkg6

//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

typedef pair<int,pair<int,int>> pi;

class Solution{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k){
        vector<int> answer(k*k);
        
        priority_queue< pi, vector<pi>, greater<pi> >q;
        
        for(int i=0;i<k;i++) q.push(make_pair(arr[i][0],make_pair(i,0)));
        
        int g = 0;
        while(!q.empty()){
            auto h = q.top(); q.pop();
            if(h.second.second+1<k)
                q.push(
                    {
                        arr[h.second.first][h.second.second+1],
                        {h.second.first,h.second.second+1}
                    }
                );
            
            answer[g] = h.first;
            g++;
        }
        
        return answer;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}