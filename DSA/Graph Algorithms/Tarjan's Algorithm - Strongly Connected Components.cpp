#include <bits/stdc++.h>
using namespace std;

const int NODES = 1e6+1;
int timer = 0, SCC = 0;
vector<int> graph[NODES];
bool visited[NODES], onStack[NODES];
int in_time[NODES], low_time[NODES];
stack<int> st;


void dfs(int node){
    visited[node] = onStack[node] = true;
    in_time[node] = low_time[node] = timer++;
    st.push(node);

    for(auto child: graph[node]){
        if(!visited[child]){ // not visited
            dfs(child);
            if(onStack[child])
                low_time[node] = min(
                    low_time[node],
                    low_time[child]
                );

        }else if(onStack[child]){ // already visited
            low_time[node] = min(
                low_time[node], 
                in_time[child]
            );
        }
    }

    if(in_time[node] == low_time[node]){
        // Printing the Strongly Connected Component
        SCC++;
        cout << "SCC #" << SCC << ": ";
        
        int v;
        do{
            v = st.top(); st.pop();
            onStack[v] = false;
            cout << v << " ";
        } while(v!=node);

        cout << endl;
    }

}


void TARJANS_ALGORITHM(){
    int nodes, edges; cin >> nodes >> edges;
    
    int x, y;
    while(edges--) cin >> x >> y, graph[x].push_back(y);

    for(int i=0;i<=nodes;i++)
        visited[i] = onStack[i] = false;

    for(int i=1;i<=nodes;i++)
        if(!visited[i]) dfs(i);

}

/*
__________________________
Test Case:
__________________________
8 12
1 2
2 3
3 1
2 8
3 4
8 4
4 8
7 8
5 4
5 7
7 6
6 5

__________________________
Output:
__________________________
SCC #1: 8 4 
SCC #2: 3 2 1 
SCC #3: 6 7 5 
__________________________

*/


int main(){
    TARJANS_ALGORITHM();
    return 0;
}