#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
	ll re =1;
	while(b)
	{
		if(b&1) re = (re*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	for(int T=1; T<=t; T++)
	{
		ll n, m ,k;
		cin >> n  >> m >> k;
		ll sum = 0;
		for(ll f = 1; f <= k; f++)
		{
			sum = (sum +( power(f,n) - power(f-1,n) + mod) * (mod + power(f,m) - power(f-1, m)) )%mod;
		}
		cout << n << " " << m  << " " << k << "  "  << sum << "\n";

	}
	return 0;
}