#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<pair<int, int>> visi;
vector<int> lo(100005);
void visi(int a,vector<int> loca, int par, vector<int> visited)
{
	lo.pb(a);
	visited[a] = 1;
	for(auto s : v[a])
	{
		if(s.second == par)
			continue;

		dfs(s.second, loca, a,visited );
		visi.pb(s);
	}
}
int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n , d;
		cin >> n >> d;
		vector<int> v(n+1), loca(n+1), visited(n+1, 0);
		int j = 0;
		for(int x =1; x<= n; x++)
		{
			cin >> vec[x];
			loca[vec[x]] = x;

		}
		for(int x = 1; x <= n; x++)
		{
			vector<pair<int ,int>> pa;
			if(x -d >=1 )
			{
				vec.pb({loca[x-d], x-d});
			}
			if(x +d <= n)
			{
				vec.pb({loca[x+d], x+d});
			}
			sort(vec.begin(), vec.end());
			for(auto se : vec)
			{
				v[x].pb(se);
			}
		}
		for(int x =1; x<= n; x++)
		{
			if(visited[x])
				continue;
			visi.clear();
			vector<pair<int, int >> v;
			dfs(x, loca, -1, v, visited);
		}

	}


}