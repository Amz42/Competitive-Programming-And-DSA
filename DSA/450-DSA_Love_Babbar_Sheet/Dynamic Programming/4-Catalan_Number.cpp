// Catalan number

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 10;
    vector<long long int> catalan(n,0);

    catalan[0] = catalan[1] = 1;
    for(int i=2;i<n;i++){
        for(int j=0;j<i;j++){
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }

    cout<<"Catalan Number:\n";
    for(int i=0;i<n;i++) cout<<"Catalan["<<i+1<<"] = "<<catalan[i]<<"\n";
}