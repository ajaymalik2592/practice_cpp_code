#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353 ;
#define ALL(v) v.begin() , v.end()
ll n, m;
vector< pair<ll ,ll > > G1[100005], G2[100005];  
typedef struct  data
{
	ll i, j, w;
	bool operator<(data a)
	{
		return w < a.w;
	}
}data;
vector<ll> parent(100005), rank1(100005,0), level1(100001), level2(100001);

void make_set(int v) {
    parent[v] = v;
    rank1[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            rank1[a]++;
    }
}
pair<ll, ll > dis1[100001][20], dis2[100001][20];

void dfs(int a, int pa, int ma, int l)
{
	level1[a] = l;
	dis1[a][0].first = pa;
	dis1[a][0].second = ma;
	for(auto s : G1[a])
	{
		if(s.first == pa)
			continue;
		dfs(s.first, a , s.second, l+1);
	}
}
void dfs1(int a, int pa, int ma, int l)
{
	level2[a] = l;
	dis2[a][0].first = pa;
	dis2[a][0].second = ma;
	for(auto s : G2[a])
	{
		if(s.first == pa)
			continue;
		dfs1(s.first, a , s.second, l + 1);
	}
}
vector<int> starting(100005), ending(1000005), parenting(100005), vertices(100005), bhaish;
int timer = 0;
void dfs3(int a, int pa, int ma)
{
	starting[a] = timer++;
	bhaish(ma);
	for(auto s : G2[a])
	{
		if(s.first == pa)
			continue;
		dfs3(s.first, a , s.second);
	}
	ending[a] = timer;
	vertices[a] = ending[a] - starting[a];
}
ll lca1(int u, int v)
{
	if(level1[u] < level1[v])
		swap(u,v);
	int f = level1[u] - level1[v];
	ll h = 0;
	for(int x = 17; x>=0; x--)
	{
		if(f >= (1<<x))
			h = max(h, dis1[u][x].second), u = dis1[u][x].first, f-= (1<<x);
	}
	if(u == v)
		return h;
	for(int p = 17; p>= 0; p--)
	if(dis1[u][p].first != dis1[v][p].first && dis1[u][p].first != -1 ) 
	{
		h = max(h, dis1[u][p].second);
		h = max(h, dis1[v][p].second);
		u = dis1[u][p].first;
		v = dis1[v][p].first;
		
	}
	h = max(h , dis1[u][0].second);
	h = max(h , dis1[v][0].second);
	return h;
}
ll lca2(int u, int v)
{
	if(level2[u] < level2[v])
		swap(u,v);
	int f = level2[u] - level2[v];
	ll h = 0;
	for(int x = 17; x>=0; x--)
	{
		if(f >= (1<<x))
			h = max(h, dis2[u][x].second), u = dis2[u][x].first, f-= (1<<x);
	}
	if(u == v)
		return h;
	for(int p = 17; p>=0; p--)
	if(dis2[u][p].first != dis2[v][p].first && dis2[u][p].first != -1) 
	{
		h = max(h, dis2[u][p].second);
		h = max(h, dis2[v][p].second);
		u = dis2[u][p].first;
		v = dis2[v][p].first;
		
	}
	h = max(h , dis2[u][0].second);
	h = max(h , dis2[v][0].second);
	return h;
}
int main()
{
	cin >> n >> m;
	vector<data> v1(m), v2(m);
	for(int x =0; x<m; x++)
	{
		cin >> v1[x].i >> v1[x].j >> v1[x].w;
		v1[x].i--, v1[x].j--;
	}
	for(int x =0; x<m; x++)
	{
		cin >> v2[x].i >> v2[x].j >> v2[x].w;
		v2[x].i--, v2[x].j--;

	}
	sort(ALL(v1));
	sort(ALL(v2));
	// parent.resize(n);
	// rank.resize(n);
	for (int i = 0; i < n; i++)
    	make_set(i);
    for (data e : v1) {
    if (find_set(e.i) != find_set(e.j)) {
        G1[e.i].push_back({e.j, e.w});
        G1[e.j].push_back({e.i, e.w});
        union_sets(e.i, e.j);
    }
	}
	for (int i = 0; i < n; i++)
    	make_set(i);
    for (data e : v2) {
    if (find_set(e.i) != find_set(e.j)) {
        G2[e.i].push_back({e.j, e.w});
        G2[e.j].push_back({e.i, e.w});

        union_sets(e.i, e.j);
    }
	}
	if(n >= 4000)
	{
		dfs3(0,-1,0);
		
		return 0;
	}
	for(int x =0; x<20; x++)
		for(int y =0; y<n; y++)
			dis1[y][x].first = -1, dis1[y][x].second = 0, dis2[y][x].first = -1, dis2[y][x].second = 0;

	dfs(0,-1, 0, 0);
	dfs1(0,-1,0, 0);

	for(int x =1; x<20; x++)
		for(int y =0; y<n; y++)
			if(dis1[y][x-1].first != -1)
				{
					dis1[y][x].first = dis1[dis1[y][x-1].first][x-1].first;
					dis1[y][x].second = max( dis1[y][x-1].second, dis1[dis1[y][x-1].first][x-1].second);
				}

	for(int x =1; x<20; x++)
		for(int y =0; y<n; y++)
			if(dis2[y][x-1].first != -1)
				{
					dis2[y][x].first = dis2[dis2[y][x-1].first][x-1].first;
					dis2[y][x].second = max( dis2[y][x-1].second, dis2[dis2[y][x-1].first][x-1].second);
				}
	ll result = 0;
	if(n < 4000)
	for(int x =0; x<n-1; x++)
	{
		for(int y =x+1; y<n; y++)
		{
			result = (result +   lca1(x,y) * lca2(x,y)) % mod;
			// cout << x << " " << y << " " << result << endl;
		}
	}
	else
	{

		dfs3(0, -1, 0);
	}
	// for(int x =0; x<n; x++)
	// {
	// 	for(int y =0; y<n; y++)
	// 		cout << x << " " << y << " " << dis1[x][y].first << " " << dis1[x][y].second << endl;
	// }
	// for(int x =0; x<n; x++)
	// {
	// 	for(int y =0; y<n; y++)
	// 		cout << x << " " << y << " " << dis2[x][y].first << " " << dis2[x][y].second << endl;
	// }

	cout << result ;
	// for(int x =0; x<n; x++)
	// {
	// 	cout << "new " << x << endl;
	// 	for(auto p: G2[x])
	// 	{
	// 		cout << p.first <<  " " << p.second << endl;
	// 	}
	// }
	return 0;
}