// Question: https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=651bd8d91d7e33a90629a70d7d38ecb4&pid=2027&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& a, int n){
    int answer = 0;
    int meh = 0;
    
    for(int i=0;i<n;i++){
        meh = max({meh + a[i], a[i], 0});
        answer = max(answer, meh);
    }
    
    return answer;
}

int main(){
	int tests; cin>>tests; while(tests-->0){
	    int n,m; cin>>n>>m;
	 
	    int mat[n][m];
	    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mat[i][j];
	    
	    int answer = INT_MIN;
	    for(int i=0;i<n;i++){                               // start from i-th row
	        vector<int> a(m, 0);
	        for(int j=i;j<n;j++){                           // add value from j-th row
	            for(int c=0;c<m;c++) a[c] += mat[j][c];     // add value into array
	            answer = max(answer, kadane(a,m));          // maximize answer using kadane
	        }
	    }
	    
	    cout<<answer<<endl;
	}
	return 0;
}