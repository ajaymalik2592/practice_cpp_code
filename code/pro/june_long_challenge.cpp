#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> terminal(n+1), sign(n+1, -1), visiting(n+1, -1);
	vector<ll> edg(m+1), exist(m+1, 1);
	vector<int> edge[m+1], vec[n+1];
	for(int x=1; x<n+1; x++)
		cin >> terminal[x];
	priority_queue< pair<ll, ll>, vector< pair<ll, ll> > , greater< pair < ll, ll > > > que;

	for(int x=1; x<m+1; x++)
		cin >> edg[x], que.push({edg[x], x});
	for(int x=1; x<(m+1); x++)
		{
			int i, j;
			cin >> i >>j;
			edge[x].push_back(i);
			edge[x].push_back(j);
		}
	// while(!que.empty())
	// {
	// 	pair<ll, ll> p = que.top();
	// 	que.pop();
	// 	ll u = edge[p.second][0], v = edge[p.second][1];
	// 	if(visiting[u]== -1 || visiting[v] == -1)
	// 	{
	// 		visiting[u] = 1;
	// 		visiting[v] = 1;

	// 	}
	// 	else
	// 	{
	// 		exist[p.second] = 0;
	// 		cout << p.second << endl;
	// 		ll a;
	// 		cin >> a;
	// 		if(a == 0)
	// 		{
	// 			int i ;
	// 			cin >> i;
	// 			cin >> terminal[i];

	// 		}
	// 		else if(a == 1)
	// 		{
	// 			int i;
	// 			cin >> i;
	// 			cin >> edg[i];
	// 		}
	// 	}
		
	// }
	cout << -1 << endl;
	for(int x=1;x<m+1;x++)
	{
		if(exist[x] )
		{
			vec[edge[x][0]].push_back(edge[x][1]);
			vec[edge[x][1]].push_back(edge[x][0]);

		}
	}
	// for(int x=0; x<=n; x++)
	// 	visiting[x] = 0;
	for(int  x = 1; x<=n; x++)
	{
		if(sign[x] != -1)
			continue;
		vector<ll> v;
		queue<ll> q ;q.push(x);
		int j = 0;
		while(!q.empty())
		{
			ll o = q.front();
			q.pop();
			v.push_back(o);
			sign[o] = j;
			for(auto p : vec[o])
			{
				if(sign[p] == -1)
				{
					q.push(p);
				}
			}
			j++;
			j%=2;

		}
		ll in , val = -1;
		for(auto f : v)
		{
			if(terminal[f] > val)
				val = terminal[f], in = f;
			sign[f] = -1;
		}
		queue<pair<ll, ll>>qu ; qu.push({in, 0LL});
		sign[in] = 0;
		while(!qu.empty())
		{
			pair<ll, ll > pa = qu.front();qu.pop();
			ll o = pa.first;
			j = pa.second;
			
			for(auto p : vec[o])
			{

				if(sign[p] == -1)
				{
					sign[p] = !j;
					qu.push({p, !j});
				}
			}
			

		}



	}
	for(int x=1;x<=n;x++)
	{
		if(sign[x] == 0)
			cout << "C";
		else
			cout << "G";
	}


	return 0;
}