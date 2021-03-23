#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
ll mod = 1e9 + 7;
ll mul(ll a, ll b)
{
	return (a*b )% mod;
}
ll power(ll a, ll b)
{
	ll re = 1;
	while(b)
	{
		while(!(b &1)){a = (a*a)%mod ; b>>=1;}
		re = (re*a)%mod;
		--b;
	}
	return re;
}
int main()
	{
	
		int t;
		cin >> t;
		while(t--)
		{
			ll n, k;
			cin >> n >> k;
			vector<ll> vec(n);
			map<ll, ll> ma;
			for(auto &a : vec)cin >> a, ma[a]++;
			if(ma.size() <= k)
			{
				cout << 0 << "\n";
				continue;
			}
			int s = ma.size();
			vector<int> v(s,0);
			vector<pair<ll,ll> >pa;
			for(auto a : ma)
				pa.pb(a);
			for(int x =s-1; x>=s -k; x--)
				v[x] = 1;
			ll ans = 1e18;
			do{
				ll g = 0;
				vector<int> bro;
				for(int x =0; x<s; x++)
					if(v[x])bro.push_back(pa[x].first);
				for(int x =0; x<s; x++)
				{
					if(!v[x])
					{
						ll f = 1e18;
						for(auto po : bro)
							f = min(f, abs(po - pa[x].first));
						g += f*pa[x].second;
					}

				}
				ans = min(ans, g);
			}while(next_permutation(ALL(v)));
			cout << ans << "\n";

		}


	}
