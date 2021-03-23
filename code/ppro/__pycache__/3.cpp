#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7, ten = 10, ten_i;
vector<ll> filled(1e5 + 1);
ll mul(ll a, ll b)
{
	return a*b % mod;
}
ll add(ll a, ll b)
{
    b %= mod;
	if(a+b > mod)return a+b-mod;
	else return a+b;
}
ll sub(ll a, ll b)
{
	if(a >= b)return a-b;
	else return (a-b + mod) % mod;
}
ll power(ll a, ll b)
{
	ll re = 1;
	while(b){
		if(b&1) re = mul(re, a);
		a = mul(a,a);
		b>>=1;
	}
	return re;
}
int len(ll a)
{
	int j =0;
	while(a)a/=10,j++;
	return j;
}

ll fun(int n, string s)
{
	 ll ans = mul(power(ten, n-1) , ll(s[0]-'0'));
	 ll k = s[0] -'0';
	 for(int x =1; x<n; x++)
	 {
	 	if(s[x]-'0' != k)
	 	{
	 		ans = add(ans, mul(pow(ten, n-x-1), ll(s[x]-'0')));
	 		k = s[x] - '0';
	 	}
	 }
	 return ans%mod;
}
ll fun1(ll a, string s)
{
	ll ans = 0;
	if(a == 1){
		ll g = s[0]-'0';
		g *= g+1;
		return g / 2;
	}
	else
	{
		vector<ll> dp(10,0);
		for(ll x =0; x<s[0]-'0'; x++)
			dp[x] = filled[a-1], ans = add(ans, mul(mul(dp[x], filled[a-1]), x));
		ll ans1 = 0;
		for(ll x =1; x<a; x++)
			ans1 = mul(ans1, ten), ans1 = add(ans1, ll(s[x]-'0'));
		ans1 = add(ans1, 1LL);
		dp[s[0] - '0'] = ans1;
		ans = add(ans, mul(mul(ans1, filled[a-1]), ll(s[0]- '0')));
		for(int x =1; x<a; x++)
		{
			ll f = 0;
			for(int y =1; y<10; y++)f = add(f, dp[y]);
			for(ll y =0; y<10; y++)
			{
				ll f1 = sub(f, dp[y]);
				f1 = mul(f1, ten_i);
				dp[y] = f1;
				ans = add(ans, mul(filled[a- x-1], y));
			}
			
			for(ll y = 0; y< 10; y++)
			{
				dp[y] = add(dp[y], filled[a-x-1]);
				ans = add(ans, mul(filled[a-x-1],  y));
			}
			
		}
		return ans;

	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	ten_i = power(10LL, mod-2);
	filled[0] = 1;
	for(int x =1; x<= 1e5; x++)filled[x] = mul(filled[x-1], ten);
	cin >> t;
	while(t--)
	{
		ll l,r;
		string s1, s2;
		cin >> l >> s1;
		cin >> r >> s2;
		ll ans = fun1(r, s2);
		ans = add(ans, fun(l, s1));
		ans = sub(ans, fun1(l, s1));
		cout << ans << "\n";
	}
	return 0;
}
