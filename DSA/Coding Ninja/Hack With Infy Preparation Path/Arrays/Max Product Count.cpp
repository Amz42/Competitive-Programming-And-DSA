// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468987

#include <bits/stdc++.h>
using namespace std;

void maxProductCount(vector<int> &a, int n) {
    unordered_map<long long,int> mp;
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            mp[(long long)a[i]*(long long)a[j]]++;
    
    long long prod = 0, freq = 0;
    for(auto k: mp){
        if(k.second>freq){
            freq = k.second;
            prod = k.first;
        }
        if(k.second==freq)
            prod = min(prod, k.first);
    }
    
    if(prod==0 || freq<2){
        cout <<0;
    }else{
        cout << prod << " " << (freq*(freq-1)/2);
    }
    cout << endl;
}

int main(){
    return 0;
}