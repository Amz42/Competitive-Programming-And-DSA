// Question: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=2dc742840fda82dc1ccb494f3f7f91d3&pid=702382&user=amanguptarkg6

// You can simply use count of '0','1' & '2' to arrange elements in sorted order


#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    // coode here
    sort(a,a+n);
}