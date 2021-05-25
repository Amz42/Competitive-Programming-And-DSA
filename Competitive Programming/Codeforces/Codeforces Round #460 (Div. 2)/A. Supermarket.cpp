// Question: https://codeforces.com/contest/919/problem/A
// Solution: https://codeforces.com/contest/919/submission/88814676

#include <stdio.h>
int main(){
    double d = 100.00000000;
    int n,k; scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        float a,b; scanf("%f%f",&a,&b);
        if(a/b<d){d=a/b;}
    }
    printf("%.8f",(float)d*k);
	return 0;
}