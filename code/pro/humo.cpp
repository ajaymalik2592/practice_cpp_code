#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll > pll;
#define mk make_pair
#define pb push_back
ll mod = 1000003;
int main()
{
	int n,k;
	cin >> n >> k;
	int inf = 1<<30;
	vector<int> vec[n], route[n];
	for(int x=0;x<n;x++)
	{
		for(int y=0; y<n;y++)
		{
			int i;
			cin >> i;
			vec[x].pb(i);
			route[x].pb(inf);
		}
	}
	vec[0][0] = 0;
	priority_queue<pair <int,  pair<int, int> >, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>> > >  que;
	que.push(make_pair(0,make_pair(0,0)));
	while(!que.empty())
	{
		pair<int, pair<int, int> > pa = que.top();
		que.pop();
		int d = pa.first, x = pa.second.first, y = pa.second.second;
		if(y -1 >= 0 && route[x][y] == inf)
		{
			route[x][y-1] = d + vec[x][y-1];
			que.push(mk(route[x][y-1], mk(x, y-1)));

		}
		if(y +1 < n  && route[x][y+1] == inf)
		{
			route[x][y+1] = d + vec[x][y+1];
			que.push(mk(route[x][y+1], mk(x, y+1)));
		}
		if(x -1 >=0 && route[x-1][y] == inf)
		{
			route[x-1][y] = d + vec[x-1][y];
			que.push(mk(route[x-1][y], mk(x-1, y)));
		}
		if(x+1<n && route[x+1][y] == inf)
		{
			route[x+1][y] = d + vec[x+1][y];
			que.push(mk(route[x+1][y], mk(x+1, y)));
		}

	}
	int d = 1;
	for(int x=0; x<n;x++)
	{
		for(int y =0; y <n;y++)
		{
			if(route[x][y] <= k)
			{
				d = max(d, (x+1)*(y+1));
			}
		}
	}
	cout << d ;
}