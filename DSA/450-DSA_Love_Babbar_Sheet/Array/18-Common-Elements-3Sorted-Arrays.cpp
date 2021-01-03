// Question: https://practice.geeksforgeeks.org/problems/common-elements1132/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3a3bbdd5626598d5902a7403b668b82a&pid=702768&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            int i,j,k;
            i = j = k = 0;
            
            vector<int> answer;
            
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j] && B[j]==C[k]){
                    if(
                        (answer.size()!=0 && answer[answer.size()-1] != A[i]) ||
                        (answer.size()==0)
                    ) answer.push_back(A[i]);
                    i++,j++,k++;
                }
                else if(A[i]<B[j] && A[i]<C[k]) i++;
                else if(B[j]<A[i] && B[j]<C[k]) j++;
                else if(C[k]<A[i] && C[k]<B[j]) k++;
                else if(A[i]==B[j] && A[i]<C[k]) i++, j++;
                else if(B[j]==C[k] && B[j]<A[i]) j++, k++;
                else if(A[i]==C[k] && C[k]<B[j]) i++, k++;
            }
            
            return answer;
        }

};

// APPROACH:
// Use merging technique of merge sort

int main (){
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}