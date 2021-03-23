#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define ALL(a) (a).begin() , a.end()

int mod = 1e9 + 7;

int add(int a, int b){
	if(a + b >= mod)return a+ b - mod;
	return a + b;
}
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int power(int a, int b){
	if(b < 0)return 0;
	int re = 1;
	while(b){
		if(b&1){
			re = mul(re, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return re;
}
int const N = 513;
int fact[N], inverse[N];
void FAC(){
 	fact[0] = 1;
	for(int x = 1; x< N; x++){
		fact[x] = mul(fact[x-1], x);
	}
	inverse[N-1] = power(fact[N-1], mod -2);
	for(int x = N-2; x>= 0; x--){
		inverse[x] = mul(x + 1, inverse[x+1]);
	}

 }

int ncr(int a, int b){
	if(a < b)return 0;
	return mul(fact[a], mul(inverse[a-b], inverse[b]));
}


/******************************************************/

vector<int> edges[N], degree(N,0), visit(N, 0), temp;
int matrix[N][N];

int dfs(int a){
	temp.pb(a);
	visit[a] = 1;
	for(auto b : edges[a]){
		if(visit[b] == 0){
			dfs(b);
		}
	}
}

void solve(){
	int n, m , A, R;
	cin >> n >> m >> A >> R;
	vector<pair<int,int>> pa;
	for(int x =0;x<m; x++){
		int u, v;
		cin >> u >> v;
		pa.pb({u , v});
		degree[u]++;
		degree[v]++;
		edges[u].pb(v);
		edges[v].pb(u);
		matrix[min(u, v)][max(u, v)] =  1;
	}

	vector<vector<int>> answer;
	for(int x =1; x<=n; x++){
		if(visit[x] == 0){
			dfs(x);
			int s = 0;
			for(auto a : temp){
				s += degree[a];
			}
			int node = temp.size();
			node = node* (node-1) /2;
			s /= 2;
			ll cost1 = temp.size() * A + R * (node - s), cost2 = s * A;
			if(node == s && node > 0){
				for(auto a : temp){
					for(auto b : temp)
						matrix[min(a, b)][max(a, b)] = 0;
				}
				vector<int> v = {1, int(temp.size())};
				for(int y = 0; y<temp.size()-1; y++){
					v.pb(temp[y]);
					v.pb(temp[y+1]);
				}
				v.pb(temp[temp.size() -1]);
				v.pb(temp[0]);
				answer.pb(v);
			}
			else if(cost1 < cost2){
				vector<int> v = {1, int(temp.size())};
				for(int y = 0; y<temp.size()-1; y++){
					v.pb(temp[y]);
					v.pb(temp[y+1]);
				}
				v.pb(temp[temp.size() -1]);
				v.pb(temp[0]);
				answer.pb(v);

				for(auto a : temp){
					for (auto b : temp){
						if(b > a && matrix[a][b] == 0){
							vector<int> der = {2, a, b};
							answer.pb(der);

						}
						matrix[a][b] = 0;
					}
				}
				// for(auto a : temp){
				// 	for(auto b : temp)
				// 		matrix[min(a, b)][max(a, b)] = 0;
				// }


			}
			else{
				map<pair<int,int>,int> ma;
				int n1 = temp.size();
				for(int x1 =0; x1<n1; x1++){
					for(int y = x1 + 1; y<n1; y++){
						for(int z = y + 1; z <n; z++){
							if(matrix[x1][y] && matrix[y][z] && matrix[x1][z]){
								if(ma.count({x,y}) ){
									int c = ma[{x1, y}] ;
									ma.erase(ma.find({x1, y}));
									matrix[c][x1] = matrix[c][ y] = matrix[x1][y] = matrix[x1][z] = matrix[y][z] = 0;
									if(matrix[c][z]){
										matrix[c][z] = 0;
										answer.pb({1, 4, c, x1, x1, y, y, z, c, z});
									}
									else{
										answer.pb({1, 4, c, x1, x1, y, y, z, c, z});
										answer.pb({2, c, z});
									}
								}
								else{
									ma[{y, z}] = x;
								}
							}
						}
					}
				}

			}

			temp.clear();
		}
	}
	for(int x = 1; x<=n; x++){
		for(int y = x +1; y<= n; y++){
			for(int z = y+1; z<=n; z++){
				if(matrix[x][y] && matrix[y][z] && matrix[x][z]){
					matrix[x][y] = matrix[y][z] = matrix[x][z] = 0;
					answer.pb({1,2,x,y,y,z});
				}
			}
		}
	}
	for(int x =1; x<=n; x++){
		for(int y = x +1; y<=n; y++){
			if(matrix[x][y]){
				matrix[x][y] = 0;
				answer.pb({1,1,x,y});
			}
		}
	}


	cout << answer.size() << "\n";
	for(auto a : answer){
		for(auto B: a){
			cout << B  << " "; 
		}
		cout << "\n";
	}
}


/******************************************************/
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	// cin >> t;
	while(t--){
		solve();
	}

}