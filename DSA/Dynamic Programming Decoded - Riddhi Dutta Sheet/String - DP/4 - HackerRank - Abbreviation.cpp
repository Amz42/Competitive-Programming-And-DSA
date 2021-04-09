// Question: https://www.hackerrank.com/challenges/abbr/problem
// Solution: https://www.hackerrank.com/rest/contests/master/challenges/abbr/hackers/aman_18bit1002/download_solution
// Comment: https://www.hackerrank.com/challenges/abbr/forum/comments/954640

#include <bits/stdc++.h>
using namespace std;

string A, B;
int dp[1001][1001];

int fun(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(j==B.size()){
        while(A[i]){
            if('A'<=A[i] && A[i]<='Z')
                return dp[i][j] = 0; // string not ok
            i++;
        }
        return dp[i][j] = 1; // string ok
    }
    if(i==A.size())
        return dp[i][j] = 0; // string not ok
    if('A'<=A[i] && A[i]<='Z'){
        if(A[i]!=B[j]) return dp[i][j] = 0; // string not ok
        else return dp[i][j] = fun(i+1, j+1);
    }
    
    char c = toupper(A[i]);
    return dp[i][j] = (c == B[j] ? fun(i+1, j+1) : 0) || fun(i+1, j);
}


// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    A = a, B = b;
    memset(dp, -1, sizeof dp);
    return (fun(0,0) == 1 ? "YES" : "NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}