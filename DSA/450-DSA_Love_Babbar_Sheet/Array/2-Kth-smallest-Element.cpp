// Question: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6424124f93dbaa71eac2c7fa33cf4528&pid=701747&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    int freq[100001]={0};
    for(int i=l;i<=r;i++) freq[arr[i]]++;
    
    int sum=0;
    for(int i=0;i<100001;i++){
        if(sum+freq[i]<k) sum += freq[i];
        else{
            return i;
            break;
        }
    }
}