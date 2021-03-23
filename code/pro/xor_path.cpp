#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1e9 + 7;
vector<ll> stored(200001, 0 );
vector<pair< ll , ll >> vec[100001];
// int DP[100001][20];
// vector<int> parents;
int i = 0;
vector<int> start(100001), ending(100001), parent(100001), XOR(100001);
void dfs(int a, int par, int ans)
{
	
	
	
	XOR[a] = ans;
	// DP[a][0] = par;
	for(auto s : vec[a])
	{
		if(s.first == par)
			continue;

		dfs(s.first, a, ans ^ s.second);

	}
}

ll power(ll a, ll b)
{
	ll re = 1;
	while(b)
	{
		if(b&1) re = (re *a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return re;
}

int main()
{
	ll n;
	cin >> n;
	
	for(int x =0; x<n-1; x++)
	{
		ll i, j, z;
		cin >> i >> j >> z;
		// i--, j--;
		vec[i].pb({j, z});
		vec[j].pb({i, z});

	}
	
	
	ll ans = n*n;
	
	dfs(1,-1, 0);
	// int maxi = 16;
	// for(int x =1; x<= 16; x++)
	// {
	// 	for(int y=1; y<= n; y++)
	// 	{
	// 		if(DP[y][x-1] != -1)
	// 			DP[y][x] = DP[DP[y][x-1]][x-1];
	// 	}
	// }
	vector<ll> lol(200000,0);
	for(int x = 1; x<=n; x++)
		lol[XOR[x]]++;
	vector<pair<ll , ll>> pa;
	for(ll x =0; x<200000; x++)
		if(lol[x] != 0)pa.pb({x,lol[x]});

	for(int x =0; x< pa.size(); x++)
	{
		stored[0] += (pa[x].second * (pa[x].second - 1))/2;
		for(int y=x+1; y<pa.size(); y++)
		{
			
			stored[ pa[x].first ^ pa[y].first] +=  pa[x].second * pa[y].second;
		}
	}
	ll ans1 = 0, ans2 = 0;
	for(int x = 0; x<= 200000; x++)
	{
		ans1 += (8LL* stored[x] * stored[x] ) % mod ;
		for(int y =0; y<= 16; y++)
		{
			if((x ^ (1<<y)) <= 200000 )
			ans1 += (8LL *stored[x] * (stored[x ^ (1<<y)]))%mod;
		}
		ans1 %= mod;
	}
	ans1 *= power(2ll, mod-2);
	ans1 %= mod;

	for(int x = 0; x<=19; x++)
	{
		if((1<<x) <= 200000)
		ans += n * stored[1<<x] * 4LL;
	}
	ans += n*(stored[0]) * 4LL;
	ans %= mod;
	
	cout << (ans+ans1 + ans2) % mod;
}