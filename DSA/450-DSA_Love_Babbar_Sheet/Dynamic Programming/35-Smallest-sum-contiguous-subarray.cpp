// Article: https://www.geeksforgeeks.org/smallest-sum-contiguous-subarray/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {2, 6, 8, 1, 4};//{3, -4, 2, -3, -1, 7, -5}; 
    int n = sizeof(a) / sizeof(a[0]);

    int mneh = 0;
    int answer = INT_MAX;

    for(int i=0;i<n;i++){
        mneh = min(a[i], mneh + a[i]);
        answer = min(answer, mneh);
    }

    cout << "Smallest Sum Contiguous Subarray: " << answer;

    return 0;
}