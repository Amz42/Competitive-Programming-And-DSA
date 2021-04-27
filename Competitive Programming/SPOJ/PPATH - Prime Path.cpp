// Question: https://www.spoj.com/problems/PPATH/
// Solution: https://www.spoj.com/submit/PPATH/id=26169876

#include <bits/stdc++.h>
#define ll long long
#define u_map unordered_map
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define fori(n) for(ll int i=0;i<n;i++)
#define forj(n) for(ll int j=0;j<n;j++)
#define MOD 1000000007 // 1e9+7
#define ten5 100000
#define ten6 1000000
#define ten9 1000000000
#define maxv(v) *max_element(v.begin(),v.end()) // to find max element of a vector
using namespace std;

vector<int> adj[100001];
vector<int> primes;
int dist[100001];
bool visited[100001]={0};

bool isPrime(ll int n){
    for(ll int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

bool isValid(int a,int b){
    string aa = to_string(a);
    string bb = to_string(b);
    sht int c = 0;
    for(ll int i=0;i<4;i++){
        if(aa[i]!=bb[i]) c++;
    }
    return c!=1 ? false : true;
}

void graph(){
    for(int i=1001;i<=9999;i++){
        if(isPrime(i)) primes.pb(i);
    }
    
    int a,b;
    for(int i=0;i<(int)primes.size();i++){
        for(int j=i+1;j<(int)primes.size();j++){
            a = primes[i]; b = primes[j];
            if(isValid(a,b)) adj[a].pb(b), adj[b].pb(a);
        }
    }
}

void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = 1;
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        visited[a] = true;
        for(auto k: adj[a]){
            if(!visited[k]) visited[k]=1, dist[k] = dist[a]+1, q.push(k);
        }
    }
}

int main(){
    optimize
    /////// Write from here
    
    graph();
    
    ll int t,x,y; cin>>t;
    while(t--){
        cin>>x>>y;
        
        fori(100001) visited[i]=0, dist[i]=-1;
        
        bfs(x);
        
        if(dist[y]==-1) cout<<-1;
        else cout<<dist[y];
        NL
    }
    
	return 0;
}