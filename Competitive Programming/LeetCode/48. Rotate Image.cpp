// Question: https://leetcode.com/problems/rotate-image/
// Solution: https://leetcode.com/submissions/detail/491170714/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for(int i=0;i<m.size()/2;i++){
            int a[] = {i,i};            // top left
            int b[] = {i,i+n-1};        // top right
            int c[] = {i+n-1,i+n-1};    // bottom right
            int d[] = {i+n-1,i};        // bottom left
            for(int j=0;j<n-1;j++){
                int tmp = m[a[0]][a[1]];
                m[a[0]][a[1]] = m[d[0]][d[1]];
                m[d[0]][d[1]] = m[c[0]][c[1]];
                m[c[0]][c[1]] = m[b[0]][b[1]];
                m[b[0]][b[1]] = tmp;
                
                a[1]++; // j++
                b[0]++; // i++
                c[1]--; // j--
                d[0]--; // i--
            }
            n-=2;
        }
    }
};

int main(){
    return 0;
}