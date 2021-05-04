// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468989

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int *a, int n){
    int idx = 0, dec = 0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) dec++, idx = i;
    }
    
    if(dec == 0) return true;
    if(dec>1) return false;
    if(idx==0 || idx==n-2 || a[idx-1]<=a[idx+1] || a[idx]<=a[idx+2]) return true;
    
    return false;
}

int main(){
    return 0;
}