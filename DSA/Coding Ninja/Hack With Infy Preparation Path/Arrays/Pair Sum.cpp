// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468985

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(int arr[], int n, int S){
    const int K = 1e5+1;
    int pos[K] = {0}, neg[K] = {0};
    
    vector<vector<int>> answer;
    
    vector<int> v;
    for(int i=0;i<n;i++){
        int e = arr[i];
        if(e < 0) neg[abs(e)]++;
        else pos[e]++;
    }
    
    for(int i=-K+1;i<0;i++){
        int a = i; // a is negative
        int b = S-i;
        
        if(b>=0 && b<K){ // b is positive
            int range = neg[abs(a)]*pos[abs(b)];
            for(int x=0;x<range;x++)
            	v.push_back(a), v.push_back(b);
        	neg[abs(a)] = pos[abs(b)] = 0;
        }
        
        if(b<0 && -K<b){ // b is negative
            int range = (a==b ? (neg[abs(a)]*(neg[abs(a)]-1))/2 : neg[abs(a)]*neg[abs(b)]);
            for(int x=0;x<range;x++)
            	v.push_back(a), v.push_back(b);
        	neg[abs(a)] = neg[abs(b)] = 0;
        }
    }
    
    for(int i=0;i<K;i++){
        int a = i;
        int b = S-i;
        
        if(b>=0 && b<K){
            int range = (a==b ? (pos[abs(a)]*(pos[abs(a)]-1))/2 : pos[abs(a)]*pos[abs(b)]);
            for(int x=0;x<range;x++)
            	v.push_back(a), v.push_back(b);
        	pos[abs(a)] = pos[abs(b)] = 0;
        }
    }
    
    for(int i=0;i<v.size();i+=2){
        vector<int> g;
        g.push_back(v[i]), g.push_back(v[i+1]);
        answer.push_back(g);
    }
    
    return answer;
}

int main(){
    return 0;
}