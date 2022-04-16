// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468968

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>a, int n){
    int KDN = -1e9, meh = 0;
    for(int i=0;i<n;i++){
        meh += a[i];
        KDN = max(KDN, meh);
        meh = max(0, meh);
    }
    
    return KDN;
}

int maxSumRectangle(vector<vector<int>>& arr, int n, int m){
    int answer = -1e9;
	for(int i=0;i<n;i++){
        vector<int> v(m, 0);
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++) v[k] += arr[j][k];
            answer = max(answer, kadane(v, m));
        }
    }
    
    return answer;
}


int main(){
    return 0;
}