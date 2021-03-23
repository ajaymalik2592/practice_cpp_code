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
	// for(int  x = 1; x<=n; x++)
	// {
	// 	if(sign[x] != -1)
	// 		continue;

	// 	queue<ll> q ;q.push(x);
	// 	int j = 0;
	// 	while(!q.empty())
	// 	{
	// 		ll o = q.front();
	// 		q.pop();
	// 		sign[o] = j;
	// 		for(auto p : vec[o])
	// 		{
	// 			if(sign[p] == -1)
	// 			{
	// 				q.push(p);
	// 			}
	// 		}
	// 		j++;
	// 		j%=2;

	// 	}
	// }
	for(int x=1;x<=n;x++)
	{
		int i = ( rand() + rand() ) % 2 ;
		if(i == 1)
			cout << "C";
		else
			cout << "G";
	}


	return 0;
}