// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468966

#include <bits/stdc++.h>
using namespace std;

int flipBits(int* arr, int n) {
	int sum = 0, KDN = 0, ones = 0;
    for(int i=0;i<n;i++) ones += (arr[i]==1);
    
    for(int i=0;i<n;i++){
        int g = (arr[i] == 1 ? -1 : +1);
        KDN = max(KDN, sum = max(sum+g, g));
    }
    
    return KDN + ones;
}

int main(){
    return 0;
}