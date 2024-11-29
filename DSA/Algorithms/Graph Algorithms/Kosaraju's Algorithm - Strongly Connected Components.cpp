// Kosaraju's Algorithm for Strongly Connected Components

#include <bits/stdc++.h>
using namespace std;

const int NODES = 1000;
vector<int> order;
vector<int> adj[NODES];              // normal graph
vector<int> transposed_adj[NODES];   // transposed graph (All edges' direction reversed)
bool visited[NODES];
vector<int> Strongly_Connected_Component;

void dfs1(int node){
    visited[node] = true;
    
    for(int child: adj[node])
        if(!visited[child])
            dfs1(child);
    
    order.push_back(node);
}

void dfs2(int node){
    visited[node] = true;
    
    for(int child: transposed_adj[node])
        if(!visited[child])
            dfs2(child);
    
    Strongly_Connected_Component.push_back(node);
}

void KOSARAJUS_ALGORITHM(){
    int n,m; cin>>n>>m;
    
    // Resetting the Data Structures
    for(int i=0;i<n;i++) adj[i].clear(), transposed_adj[i].clear(), visited[i] = false;
    order.clear();

    // Constructing both Normal & Transposed Graph
    int x,y;
    for(int i=0;i<m;i++)
        cin >> x >> y, adj[x].push_back(y), transposed_adj[y].push_back(x);
    
    // Calculating the order of SCC
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs1(i);
    
    // Resetting the visited Array
    for(int i=0;i<n;i++) visited[i] = false;

    // Finding the Strongly Connected Components
    for(int i=n-1;i>=0;i--){
        if(!visited[order[i]]){
            Strongly_Connected_Component.clear();
            dfs2(order[i]);

            cout << "Strongly Connected Component Nodes: ";
            for(int node: Strongly_Connected_Component)
                cout << node << " ";
            cout << endl;
        }
    }
}



int main(){
    KOSARAJUS_ALGORITHM();
    return 0;
}