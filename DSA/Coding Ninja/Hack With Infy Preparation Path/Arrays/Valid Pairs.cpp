// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468986

#include <bits/stdc++.h>
using namespace std;

int nxt(int e, int k, int m){
    if(m>e) return m-e;
    return (k-e+m)%k;
}

bool isValidPair(vector<int> &arr, int n, int k, int m) {
    int mod[k] = {0};
    for(auto g: arr) mod[g%k]++;
    
    for(int i=0;i<k;i++){
        int a = i;
        int b = nxt(i, k, m);
        if(
            (a==b && mod[i]&1) ||
            (a!=b && mod[a]!=mod[b])
        ) return false;
    }
    
    return true;
}

int main(){
    return 0;
}