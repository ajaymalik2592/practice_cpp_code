#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
typedef struct data
{
	int i,j,l,a,b,index;
	bool operator< (data B)
	{
		return b > B.b;
	}
}data;
vector<data> edge(256* 128 + 10);
vector<pair<int, int>> pa[300]; 
int parent[300], rank1[300];
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m,k,s;
	cin >> n >> m >> k >> s;
	vector<int> v(k), point(k, 0);
	for(auto &p : v)cin >> p;
	vector<pair<int,int> > vec(n);
	for(auto a : vec)cin >> a.first >> a.second;
	for(int x =0; x<m; x++)
	{
		cin >> edge[x].i >> edge[x].j >> edge[x].l >> edge[x].a >> edge[x].b;
		pa[edge[x].j].pb({edge[x].i,x});
		pa[edge[x].i].pb({edge[x].j,x});
		edge[x].index = x;
	}
	ll t = 1;
	// sort(edge.begin(), edge.begin()+m);
	// cout << m << endl;
	// for(int x =0; x<m; x++)
	// {

	// 	cout << t << " " << edge[x].index  + 1 << endl;
	// 	t += edge[x].l;
	// }
	
	

	cout << 0 << "\n";

	return 0;
}
