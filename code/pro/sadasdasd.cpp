#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<int> flat[n+1], upside[n+1];
	for(int x =0; x<=n; x++)
		flat[x].resize(m+1, 0), upside[x].resize(m+1,0);
	vector<string> st(n);
	for(auto &a :st) cin >> a;
	for(int x =0; x<m; x++)
		upside[n-1][x] = 1;
	for(int x =0; x<n; x++)
		flat[x][m-1] = 1;
	for(int x = 0; x<n; x++)
	{
		for(int y =m-2; y>=0; y--)
			if(st[x][y] == st[x][y+1])
				flat[x][y] = flat[x][y+1] + 1;
			else
				flat[x][y] =1;
	}
	for(int x = n-2; x>=0; x--)
	{
		for(int y =m-1; y>=0; y--)
			if(st[x][y] == st[x+1][y])
				upside[x][y] = upside[x+1][y] + 1;
			else
				upside[x][y] =1;
	}
	ll sum = 0;
	for(int x =0; x<n; x++)
	{
		for(int y = 0; y<m; y++)
		{
			int u = upside[x][y];
			if(x + 3*u <= n && upside[x + u][y] == u && upside[x+2*u][y] >= u)
			{
				int  p = n;
				for(int z = x; z< x + u*3; z++)
					p = min(flat[z][y], p);
				sum += p;
			}
		}
	}
	cout << sum;

}
