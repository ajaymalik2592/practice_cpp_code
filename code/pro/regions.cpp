#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mk make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
 
ll n, m, k, l,mod = 1000000007,p;
ll dp[1000009][3];
int  visited[1000009][3];
ll go(ll a, ll c,  ll b, ll j)
{
	if(b == 0)
	{
			return 1LL;
	}
	if(a > j || b < 0) return 0LL;
	
	if(visited[a][c]) 
		return dp[a][c];
 
	visited[a][c] = 1;
 
	ll &ans = dp[a][c];
 
	ans = ( go(a+1, 0LL, b, j) + 
 
		m * ( b == k ? go(a +l, 1LL, b-1, min(j, n-l+a)) : go(a+l, 1LL, b-1, j) ) + 
 
		p * (b==k ? go(l+a, 2LL, b-2, min(j, n-l+a)) : go (a +l , 2LL , b-2 , j) ) )% mod;
	return ans;
}
	
 
int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		int t;
		cin >> t;
		while(t--)
		{
			
			cin >> n >> m >> k >>l;
			p = ((m*(m-1))/2) % mod;
			F(x,0,n+2)F(y,0,2) visited[x][y] = 0, dp[x][y] = 0;
 
			ll u = go(0LL, 0LL, k, n);
			cout << dp[1][0] << "\n" ;
 
			
		}	
	}
