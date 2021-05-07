// PERFECT MATCHING IN GRAPHS(TREE)

#include <bits/stdc++.h>
using namespace std;

const int NODES = 1e6+1;
bool perfect_matching;
vector<int> graph[NODES];

// DFS on Tree
int dfs(int node, int parent = -1){
    int val = 1;

    for(int child: graph[node]){
        if(child == parent) continue;
        val = val - dfs(child);
    }

    // if value at any points falls negative
    //                        OR
    // at root node the value remains 1 (i.e. no pair is formed for root node)
    //
    // ==>> then perfect matching can't exist
    if(val<0 || (val==1 && parent==-1))
        perfect_matching = false;

    return val;
}

void PERFECT_MATCHING(){
    int nodes; cin>>nodes;

    // Undirected Graph (TREE) (number of edges = nodes-1, Single Connected Component)
    int x,y;
    for(int i=0; i<nodes-1; i++) cin>>x>>y, graph[x].push_back(y), graph[y].push_back(x);

    int root = 0;
    perfect_matching = true;
    dfs(root);

    if(perfect_matching)
        cout<<"PERFECT MATCHING EXISTS";
    else
        cout<<"PERFECT MATCHING DOESN'T EXISTS";
}



int main(){
    PERFECT_MATCHING();
    return 0;
}