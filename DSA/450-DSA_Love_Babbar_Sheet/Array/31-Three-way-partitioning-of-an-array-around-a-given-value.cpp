// Question: https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=bf0f798ab7baf588719de25819c4ea61&pid=700455&user=amanguptarkg6

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
APPROACH:
if current element is less than 'a' then swap it with leftmost unset element
if current element is more than 'b' then swap it with rightmost unset element
else move on & check next elements
*/

class Solution{
public:
    void threeWayPartition(vector<int>& array,int a, int b){
        int l = 0, r = array.size()-1;
        int ptr = 0;
        
        while(ptr <= r){
            if(array[ptr] < a){                   // current element < a
                swap(array[ptr], array[l]);
                l++; ptr++;
            }else if(array[ptr] > b){             // current element > b
                swap(array[ptr], array[r]);
                r--;
            }else ptr++;
        }
        return;
    }
};

int main() {
    int t; cin>>t; while(t--){
        int N; cin>>N; vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){cin>>array[i]; ump[array[i]]++;}
        int a,b; cin>>a>>b;
        
        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0, kk2 = 0, kk3 = 0;
        
        for(int i=0; i<N; i++){
            if(original[i]>b) k3++;
            else if(original[i]<=b and original[i]>=a) k2++;
            else if(original[i]<b) k1++;
        }
        
        Solution ob; ob.threeWayPartition(array,a,b);

        for(int i=0;i<k1;i++) if(array[i]<b) kk1++;
        for(int i=k1;i<k1+k2;i++) if(array[i]<=b and array[i]>=a) kk2++;
        
        for(int i=k1+k2;i<k1+k2+k3;i++) if(array[i]>b) kk3++;

        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3) ok = 1;
        for(int i=0;i<array.size();i++) ump[array[i]]--;
        for(int i=0;i<array.size();i++) if(ump[array[i]]!=0) ok=0;
        if(ok) cout<<1<<endl;
        else cout<<0<<endl;
    }   
    return 0;
}