#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f(x,n,b) for(int x = (int)b; x<=n; x++)
typedef long long ll;
ll mod = 1e9 + 7;
vector<int> vec;
ll mul(ll a, ll b)
{
	return (a*b) % mod;
}
ll power(ll a, ll b)
{
	ll re =1;
	while(b)
	{
		if(1&b) re = mul(re,a);
		a = mul(a,a);
		b>>=1;
	}
	return re;
}
map<pair<int,int>,int> ma;
void dfs(pair<pair<int,int>,int> pa)
{
	vec.pb(pa.second);
	ma[pa.first] = -1;
	int x1 = pa.first.first, y1= pa.first.second;
	int x = 0, y = 0;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 0, y = 1;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 0, y = 2;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 1, y = 2;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 2, y = 2;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 2, y = 1;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 2, y = 0;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	x = 1, y = 0;
	if(ma.find({x1 + x -1, y1 + y - 1}) != ma.end() && ma[{x1+x-1, y1+y-1}] != -1)
		dfs(*ma.find({x1+x-1,y1+y-1}));
	
	


}
int main()
{
	int n,t;
	cin >> n >> t;
	
	for(int x=0; x<n; x++)
	{
		int u,v;
		cin >> u >> v;
		ma[{u,v}] = x+1;
	}
	
	
	dfs(*ma.begin());
	if(vec.size() == n)
	{
		cout << "YES\n";
		for(auto a : vec)
		{
			cout << a << "\n";
		}
	}
	else
	{
		cout << "NO\n";
 
	}
	
}