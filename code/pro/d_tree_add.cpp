#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
ll mod = 1e9 + 7;
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
ll solve(ll a, ll b)
{
	if(a < b)
		return 0;
	ll re = 1, re1 = 1;
	for(ll x =0; x<b; x++)
	{
		re = (re * (a-x)) % mod;
		re1 = (re1 * (x+1)) % mod;
	}
	return (re * power(re1, mod- 2)) % mod;
}
int main()
	{
		speed
		ll n, k;
		cin >> n >> k;
		for(ll x =1; x<=k ; x++)
		{
			cout << (solve(n-k+1, x) * solve(k -1, x-1))%mod << "\n";
		}
	}	
