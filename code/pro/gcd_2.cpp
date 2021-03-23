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
ll gcd(ll a, ll b)
{
    if(b == 0)return a;
    else return gcd(b, a%b);
}
ll fun(ll high, ll low)
{
	ll re = 0;
	re += (high * (low)*(low-1))/2 + (high*(high-1)*low)/2 + (high*(high-1)*(high-2))/6;
	return re%mod;
}
int main()
	{
		ll ma = 100000;
		vector< vector <ll> > vec(100001);
		for(ll x = 1; x <= ma; x++ )
		{
			vec[x].pb(0);
			vec[x].pb(1);
			for(ll y = 2 ; y <= ma/x; y++ )
			{
				ll g = gcd(x,y);
				if(g == 1)
				vec[x].pb(1);
				else vec[x].pb(0);
			}
			ll o = 0, h;
			for(ll y = ma/x; y>= 0; y--)
			{
				h = o + vec[x][y];
				vec[x][y] = o;
				o = h;
			}
		}
		int t;
		cin >> t;
		while(t--)
		{

			ll n;
			cin >> n;
			ll ans = 0;
			for(ll x =1; x<= n; x++)
			{
				ll d = 0;

				for(int y = x; y<= n; y+= x)
				{
					
					ll high = vec[y/x][y/x] - vec[y/x][n/x], low = n/x - y / x - high;
					d += fun(high, low);
					cout << x << " " << y << " " << high << " " << low << " " << fun(high, low) <<   endl;
				}
				ll k = x*x;
				k %= mod;
				k *= k;
				k %= mod;
				d %= mod;
				ans += (d * k) % mod;
				cout << "d  " << d << endl;
			}
			cout << ans  % mod << "\n";
		}
		return 0;
		
	}