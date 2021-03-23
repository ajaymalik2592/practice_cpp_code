#include<bits/stdc++.h>
using namespace std;

int n, q;
vector< vector<int> > edges(1 + 1e6), parent(1 + 1e6, vector<int> (21));
vector<vector<pair< int, int >>> value(1e6 + 1, vector<pair<int,int>> (1)) ;
vector<int> leaf(1e6 + 1 , 0), start(1e6 + 1 ), ending(1e6 + 1), level(1e6 + 1);
vector<pair<int,int>>last_nodes, ti[5 + 500000];
vector<long long > total(5e5 + 5 ), got(5e5 + 5);
int timer = 0, depth = 0;
void dfs(int node, int pa, int l){
	start[node] = timer++;
	level[node] = l;
	parent[node][0] = pa;
	int b = 0;
	for(int a : edges[node]){
		if(a == pa)continue;
		dfs(a, node, l + 1);
		depth = max(depth , l + 1);
		b++;
	}
	if(b == 0)leaf[node] = 1, last_nodes.push_back({start[node], node});
	ending[node] = timer;
}
void putt(int a, int time, int val){
	int i = lower_bound(last_nodes.begin(), last_nodes.end(), make_pair(start[a], -1 )) - last_nodes.begin();
	int j = upper_bound(last_nodes.begin(),last_nodes.end(), make_pair(ending[a], - 1)) - last_nodes.begin();
	for(; i<j; i++){
		if(time + level[last_nodes[i].second] - level[a] < q)
		ti[time + level[last_nodes[i].second] - level[a] - 1].push_back({last_nodes[i].second, val });
	}
}
int ma = 500;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int x = 0; x <= n-2; x++){
		int i,j;
		cin >> i >> j;
		i--, j--;
		edges[i].push_back(j);
		edges[j].push_back(i);
	}
	for(int x =0; x<n; x++) cin >> value[x][0].first, value[x][0].second = x, got[x] += value[x][0].first;
	edges[0].push_back(n);
	edges[n].push_back(0);
	for(int x = n+1; x< n + q; x++){
		edges[x].push_back(x-1);
		edges[x-1].push_back(x);
	}
	dfs(n+q-1, -1, 0);
	for(int G =1; G<21; G++){
		for(int x =0; x<n+q-1; x++){
			if(parent[x][G-1] != -1)
				parent[x][G] = parent[parent[x][G-1]][G-1];
		}
	}

	depth = depth - q;
	if(depth >= ma)
	for(int x =0; x<n; x++){
		if(leaf[x]){
			total[x] += value[x][0].first;
			continue;
		}
		putt(x, 0,  value[x][0].first);
	}
	// cout << "leaf " << endl;
	// for(int x =0; x<n; x++)if(leaf[x]) cout << x <<  "  --  ";

	for(int x =1; x <= q; x++){
		if(depth  >= ma)
		for(auto po: ti[x-1]){
			total[po.first] += po.second;
		}
		char ch;
		cin >> ch;
		if(ch == '?'){
			int node;
			cin >> node;
			node --;
			int no = node;
			int x1 = x;
			int g = 0;
			if(leaf[node] == 1){
				if(depth < ma){

					long long pop = 0;
					int h = 0;
					x1++;
					while(x1--){
						pop += got[node];
						node = parent[node][0];
						if(node == n)break;
					}
					cout << pop << "\n";
				}
				else 
				cout << total[node] << "\n";
				continue;
			}
			
			while(x1){
				if(x1 & 1){
					node = parent[node][g];
				}
				g++;
				x1 >>= 1;
			}
			// pair<long long, int > pa = value[node];
			long long pop = 0;
			for(int i = 0; i< value[node].size(); i++){
						if(start[value[node][i].second] <= start[no] && ending[value[node][i].second] >= ending[no])
							pop += value[node][i].first;
					}
			cout << pop << "\n";
		}
		else{
			int node, k;
			cin >> node >> k;
			node --;
			got[node] += k;
			int no = node;
			if(depth >= ma)
			{
				if(leaf[no]){
					total[node] += k;
					continue;
				}

				putt(node, x, k);
			}
			
			int x1 = x;
			int g = 0;
			while(x1){
				if(x1 & 1){
					node = parent[node][g];
				}
				g++;
				x1 >>= 1;
			}
			value[node].push_back({k, no});

		}
	}
	// for(int x =0; x<n; x++){
	// 	cout << x << " parent " << parent[x][0] << endl; 
	// }
}