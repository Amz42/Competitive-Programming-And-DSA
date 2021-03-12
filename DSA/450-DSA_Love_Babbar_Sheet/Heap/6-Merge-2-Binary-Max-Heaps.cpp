// Question: https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=94b8b4b26941953e4f41704012e00e21&pid=2007&user=amanguptarkg6

#include <iostream>
using namespace std;

void Heapify(int i, int n, int a[]){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    
    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;
    
    if(largest != i){
        swap(a[largest], a[i]);
        Heapify(largest, n, a);
    }
}

void BuildMaxheap(int a[], int n){
    for(int i=n/2;i>=0;i--) Heapify(i, n, a);
}

int main(){
	int tests; cin>>tests;
	while(tests--){
	    int n,m; cin>>n>>m;
	    
	    int a[n+m];
	    for(int i=0;i<n+m;i++) cin>>a[i];
	    BuildMaxheap(a, n+m);
	    
	    for(int i=0;i<n+m;i++) cout << a[i] << " ";
	    cout<<endl;
	}
	
	return 0;
}