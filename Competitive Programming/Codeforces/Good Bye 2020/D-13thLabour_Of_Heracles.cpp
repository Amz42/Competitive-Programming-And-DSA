// Question: https://codeforces.com/contest/1466/problem/D
// Solution: https://codeforces.com/problemset/submission/1466/103099262

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define MOD         (int)(1e9+7)
#define ten5        (int)(1e5)
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
using namespace std;






void solve() {
    ll int n, x, y; cin>>n;
    ll int sum_of_weight_of_nodes = 0;
    ll int weight[n];
    for(int i=0;i<n;i++) cin>>weight[i], sum_of_weight_of_nodes += weight[i];

    ll int in_degree[n]={0};
    for(int i=0;i<n-1;i++){ // edges input
        cin>>x>>y; x--,y--;
        in_degree[x]++, in_degree[y]++;
    }

    priority_queue<pair<ll int,ll int>> pq;
    for(int i=0;i<n;i++){
        in_degree[i]--;
        if(in_degree[i]) pq.push(make_pair(weight[i], in_degree[i]));
    }

    cout<<sum_of_weight_of_nodes<<" ";
    for(int i=1;i<n-1;i++){
        auto node = pq.top(); pq.pop();
        node.second--; // reducing indegree
        sum_of_weight_of_nodes += node.first;
        if(node.second) pq.push(node);
        cout<<sum_of_weight_of_nodes<<" ";
    }

    NL;
    return;
}






int main() {
    optimize

    long long int tests = 1;

    cin >> tests;

    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve();
    }

    return 0;
}