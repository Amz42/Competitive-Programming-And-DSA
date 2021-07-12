// DISJOINT SET UNION - DSU


#include<bits/stdc++.h>
using namespace std;

vector<int> DSU_Parent(1e5+1, -1);

/////////////////////////////////////////////// Normal Implementation

// Iterative
int DSU_Find(int a){
    while(DSU_Parent[a] > 0)
        a = DSU_Parent[a];
    return a;
}

// Recursive
int DSU_Find(int a){
    if(DSU_Parent[a] < 0)
        return a;
    return DSU_Find(DSU_Parent[a]);
}

void DSU_Union(int a, int b){
    DSU_Parent[a] += DSU_Parent[b];
    DSU_Parent[b] = a;
}

/////////////////////////////////////////////// Normal Implementation



/////////////////////////////////////////////// Path Compression Technique

// Iterative
int DSU_Find(int a){
    vector<int> v;
    while(DSU_Parent[a] > 0){
        v.push_back(a);
        a = DSU_Parent[a];
    }

    for(int i=0;i<v.size();i++)
        DSU_Parent[v[i]] = a;
    
    return a;
}

// Recursive
int DSU_Find(int a){
    if(DSU_Parent[a] < 0)
        return a;  
    return DSU_Parent[a] = DSU_Find(DSU_Parent[a]);
}

/////////////////////////////////////////////// Path Compression Technique



/////////////////////////////////////////////// Union by Rank Technique

vector<int> DSU_Rank(1e5+1, 1);
void DSU_Union(int a, int b){
    a = DSU_Find(a);
    b = DSU_Find(b);

    if(a == b) return;

    if(DSU_Rank[a] > DSU_Rank[b]){
        DSU_Parent[b] = a;
        DSU_Rank[a] += DSU_Rank[b];
    }else{
        DSU_Parent[a] = b;
        DSU_Rank[b] += DSU_Rank[a];
    }
}

/////////////////////////////////////////////// Union by Rank Technique