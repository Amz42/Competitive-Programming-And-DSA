// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468976

#include <bits/stdc++.h>
using namespace std;

vector <int> countSmallerOrEqual(int* a, int* b, int n, int m) {
    sort(b,b+m);
    vector<int> answer;
    
    for(int i=0;i<n;i++){
        if(b[m-1]<a[i]) answer.push_back(m);
        else{
            int l = 0, r = m-1;
            while(l<=r){
                int mid = l + ( r - l ) / 2;
                if(b[mid]>a[i]) r = mid - 1;
                else l = mid + 1;
            }
            answer.push_back(l);
        }
    }
    
    return answer;
}

int main(){
    return 0;
}