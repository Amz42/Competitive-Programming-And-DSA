// Finding (Articulation Point) OR (CUT VERTEX)

#include <bits/stdc++.h>
using namespace std;



const int NODES = 1e5+1;
vector<int> adj[NODES];
int in_time[NODES], low_time[NODES];
bool visited[NODES];
int timer = 0;

void dfs(int node, int parent = -1){
    visited[node] = true;
    low_time[node] = in_time[node] = timer++;

    int children = 0;
    for(int child: adj[node]){
        if(child == parent) continue;
        if(visited[child]){ // BackEdge
            low_time[node] = min(low_time[node], in_time[child]);
        }else{ // ForwardEdge
            dfs(child, node);
            children++;

            if(in_time[node] <= low_time[child] && parent != -1){
                // node is CUT VERTEX
                cout << "CUT VERTEX: " << node<< endl;
            }
            low_time[node] = min(low_time[node], low_time[child]);
        }
    }

    // current node is root & connecting more than 1 sub-graphs
    if(parent==-1 && children>1){
        // node is CUT VERTEX
        cout << "CUT VERTEX: " << node<< endl;
    }
}



int main(){
    return 0;
}