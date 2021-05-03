// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468975

#include <bits/stdc++.h>
using namespace std;

int lbsearch(vector<int> &a, int N, int X){
    int l = 0, r = N-1;
    while(l<=r){
        int mid = l + ( r - l ) / 2;
        if(a[mid] == X && (mid==0 || a[mid-1]!=X)) return mid;
        else if(a[mid]<X) l = mid+1;
        else r = mid-1;
    }
    
    return -1;
}

int hbsearch(vector<int> &a, int N, int X){
    int l = 0, r = N-1;
    while(l<=r){
        int mid = l + ( r - l ) / 2;
        if(a[mid] == X && (mid==N-1 || a[mid+1]!=X)) return mid;
        else if(a[mid]>X) r = mid-1;
        else l = mid+1;
    }
    
    return -1;
}

pair<int, int> findFirstLastPosition(vector<int> &arr, int N, int X){
	return make_pair(
    	lbsearch(arr, N, X),
        hbsearch(arr, N, X)
    );
}

int main(){
    return 0;
}