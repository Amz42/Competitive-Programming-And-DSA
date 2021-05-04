// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468984

#include <bits/stdc++.h>
using namespace std;

int fnd(vector<int> a, int l, int r){
    if(r<l) return 0;
    return (a[r] - a[l-1]);
}

int paintTheFence(vector<vector<int>>& ranges, int n, int q){
    vector<int> ones(n+5, 0), twos(n+5, 0), cf(n+5, 0);
    int total = 0;
    
    for(auto k: ranges){
        cf[k[0]]++;
        cf[k[1]+1]--;
    }
    
    for(int i=1;i<n+1;i++){
        cf[i] += cf[i-1];
        if(cf[i]==1) ones[i]++;
        if(cf[i]==2) twos[i]++;
        total += (cf[i]>0);
    }
    
    for(int i=1;i<n+1;i++) ones[i] += ones[i-1];
    for(int i=1;i<n+1;i++) twos[i] += twos[i-1];
    
    int answer = 0;
    for(int i=0;i<q;i++){
        for(int j=i+1;j<q;j++){
            int a = ranges[i][0], b = ranges[i][1];
            int c = ranges[j][0], d = ranges[j][1];
            if(a>c) swap(a,c), swap(b,d);
            
            if(a<=c && c<=b){ // overlap OR Nested
                if(d<=b){ // nested
                    answer = max(
                        total
                        - fnd(ones, a, c-1)
                        - fnd(twos, c, d)
                        - fnd(ones, d+1, b),
                        answer
                    );
                }else{ // overlap
                    answer = max(
                        total
                        - fnd(ones, a, c-1)
                        - fnd(twos, c, b)
                        - fnd(ones, b+1, d),
                        answer
                    );
                }
            }else{ // no intersection
                answer = max(
                    total
                    - fnd(ones, a, b)
                    - fnd(ones, c, d),
					answer
                );
            }
        }
    }
    
    return answer;
}

int main(){
    return 0;
}