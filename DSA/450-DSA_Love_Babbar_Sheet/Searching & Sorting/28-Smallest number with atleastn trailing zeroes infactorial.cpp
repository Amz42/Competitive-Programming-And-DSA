// Question: https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=14caed9e63f8345db49addd26d583281&pid=702829&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    int power_of_5(int n){
        int answer = 0;
        while(n) answer += n/5, n /= 5;
        return answer;
    }
    public:
    int findNum(int n){
        int l = 0, r = 1e12, answer = INT_MAX;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(power_of_5(mid) >= n){
                answer = mid;
                r = mid-1;
            }else l = mid+1;
        }
        
        return answer;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends