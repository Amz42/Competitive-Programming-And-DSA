// Question: https://practice.geeksforgeeks.org/problems/max-rectangle/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=dd1555f804eb4e57a024d9b5702f50c7&pid=700288&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int M[MAX][MAX];
    int T; cin >> T; while (T--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> M[i][j];
        cout << maxArea(M, n, m) << endl;
    }
}

///////////////////////////////////////////////////////////////////
int maxAreaHistogram(vector<int> v){
    stack<int> s;
    int left[(int)v.size()];
    int max_Area = 0;
    
    // finding just smaller bar on left side
    for(int i=0;i<(int)v.size();i++){
        while(!s.empty() && v[s.top()]>=v[i]) s.pop();
        left[i] = (s.empty() ? i : i-s.top()-1);
        s.push(i);
    }
    
    while(!s.empty()) s.pop();
    
    for(int i=v.size()-1;i>=0;i--){
        while(!s.empty() && v[s.top()]>=v[i]) s.pop();
        max_Area = max(
            max_Area,
            (int)(
                left[i] +
                1 +
                ( s.empty() ? v.size()-i-1 : s.top()-i-1 )
            ) * v[i]
        );
        s.push(i);
    }
    
    return max_Area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    vector<int> v(m,0);
    int answer = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]) v[j] += 1;
            else v[j] = 0;
        }       
        answer = max(answer, maxAreaHistogram(v));
    }
    
    return answer;
}