// Question: https://www.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/

#include<bits/stdc++.h>
using namespace std;

int parent[100005];

int DSU_Find(int a){
	if(parent[a] < 0)
		return a;
	return parent[a] = DSU_Find(parent[a]);
}

void DSU_Union(int a, int b){
	parent[a] = min(parent[a], parent[b]);
	parent[b] = a;
}

int main(){
	int n, m, a, b; cin>>n>>m;

	for(int i=1;i<=n;i++)
		parent[i] = -i;

	while(m--){
		cin>>a>>b;
		a = DSU_Find(a);
		b = DSU_Find(b);
		
		if(a != b)
			DSU_Union(a, b);
	}

	int q; cin>>q;
	while(q--){
		cin>>a>>b;
		int parent_a = DSU_Find(a);
		int parent_b = DSU_Find(b);

		if(parent_a == parent_b) cout<<"TIE";
		else{
			if(parent[parent_a] < parent[parent_b])
				cout << a;
			else
				cout << b;
		}
		cout << endl;
	}

    return 0;
}