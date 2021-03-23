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
ll mod = 1000000007;
ll power(ll a, ll b)
{
	ll re = 1;
	while(b)
	{
		if(b & 1)
		{
			re *= a;
			re %= mod;
		}
		a *= a;
		a %= mod;
		b>>=1;
	}
	return re;
}
int main()
	{
	    
	    ll n, a = 2;
	    cin >> n;
	    vector <pair <ll, ll>> vec;
	    for(int x =1; x <= n;x++)
	    {
	    	int i;
	    	cin >> i;
	    	vec.pb(make_pair(i, x));

		}
		sort(ALL(vec));
		ll p = 0;
		for(int x=0; x<n; x++)
		{
			for(int y = x +1; y < n && vec[y].first - vec[x].first <= 1; y++)
			{
				ll i , j ;
				i = max(vec[y].second, vec[x].second);
				j = min(vec[y].second , vec[x].second);
				p += power(a,  n - i) * power(a, j - 1);
				p %= mod;
			}
		}
		cout << p;
}