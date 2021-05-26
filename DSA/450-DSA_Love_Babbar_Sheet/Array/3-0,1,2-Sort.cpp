// Question: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// Solution-1: https://practice.geeksforgeeks.org/viewSol.php?subId=2dc742840fda82dc1ccb494f3f7f91d3&pid=702382&user=amanguptarkg6
// Solution-2: https://practice.geeksforgeeks.org/viewSol.php?subId=8cc25bad8ea8e86b50e0763f9c3e4b1f&pid=702382&user=amanguptarkg6

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

/////////////////////////////////////////////////////////////////////////////////////////////
class Solution2{
public:
    void sort012(int a[], int n){
        int p = 0;
        for(int i=0;i<n;i++){
            if(a[i] == 0)
                swap(a[i], a[p++]);
        }
        p = n-1;
        for(int i=n-1;i>=0;i--){
            if(a[i] == 2)
                swap(a[i], a[p--]);
        }
    }
    
};
/////////////////////////////////////////////////////////////////////////////////////////////