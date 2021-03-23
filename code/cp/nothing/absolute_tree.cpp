#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > edges(1 + 1e6);
vector<long long> value(1e6 + 1),parent(1e6 + 1);
vector<int> leaf(1e6);
void dfs(int node, int pa){
	
	parent[node] = pa;
	int b =0;
	for(int a : edges[node]){
		if(a == pa)continue;
		dfs(a, node);
		b = 1;
	}
	leaf[node] = b;
}
void dfs1(int node, long long va){
	for(int a : edges[node]){
		if(a == parent[node])continue;
		dfs1(a, value[node]);
	}
	if(leaf[node] == 1)
		value[node] = va;
	else
	value[node] += va;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int x = 0; x <= n-2; x++){
		int i,j;
		cin >> i >> j;
		i--, j--;
		edges[i].push_back(j);
		edges[j].push_back(i);
	}
	for(int x =0; x<n; x++) cin >> value[x];
	dfs(0, -1);
	for(int x =1; x <= q; x++){
		char ch;
		cin >> ch;
		if(ch == '?'){
			dfs1(0, 0);
			int node;
			cin >> node;
			node --;
			cout << value[node] << "\n";

		}
		else{
			dfs1(0, 0);
			int node, k;
			cin >> node >> k;
			node --;
			value[node] += k;

		}

	}
}