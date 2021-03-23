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
			
			vector<ll> vec(n), co(n,0);
			map<ll,ll> ma;
			for(auto &a :vec)cin >> a, ma[a]++;
			if(n == 1){
			    cout << 0 << "\n";
			    continue;
			}
			for(int x =0; x<n; x++)
			{
				for(int y =x+1; y<n; y++)
				{
					co[x] += (vec[x] > vec[y]);
				}
			}

			ll ans = 0;
			for(int x =0; x<n; x++)
			{
				ans += co[x]*k;
			} 
			ll o = 0;
			ans %= mod;
			for(auto s : ma)
			{
				ll oop= mul(k*(k-1)/2, o); 
				oop = mul(oop,s.second);
				ans += oop;
				o += s.second;
			}

			ans %= mod;
			ll q = power(n*k, mod -2);
			cout << mul(ans, q) << "\n";
			
			
			
		}


	}
