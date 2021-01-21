// Question: https://practice.geeksforgeeks.org/problems/product-array-puzzle/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=be17428fb21e106b062f718240fbb2e1&pid=702020&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );
int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<long long int> arr(n),vec(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vec = productExceptSelf(arr,n);
        for(int i=0;i<n;i++) cout << vec[i] << " ";
        cout<<endl;
    }
	return 0;
}

typedef long long ll;

vector<long long int> productExceptSelf(vector<long long int>& v, int n) {
    long long int right[n]; right[n-1] = 1;
    long long int prod = 1;
    for(int i=n-2;i>=0;i--){
        prod *= v[i+1];
        right[i] = prod;
    }
    
    vector<long long int> answer; prod = 1;
    
    for(int i=0;i<n;i++){
        answer.push_back(prod*right[i]);
        prod *= v[i];
    }   
    return answer;
}