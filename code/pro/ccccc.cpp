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
ll gcd(ll a, ll b)
{
	if(!b)return a;
	else return gcd(b,a%b);
}
bool ret;
set <ll> se {2 , 3, 5, 7};

bool pr(ll a )
{
	ret = true;
	ll e = a;
	int w = e%10;
	e /= 10;
    if(se.find(w) != se.end())
		{
			if(a % w != 0)
				{
					ret = false;
			}
		}
	while(e && ret)
	{
		ll w1 = e % 10;
		ll o =gcd(w, w1);
		if(o == 1) 
			{ret = false; break;}
		if(se.find(w1) != se.end())
		{
			if(a % w1 != 0)
				{
					ret = false;
					break;
			}
		}
		w = w1;
		e /= 10;
	}
	return ret;
}
int main()
	{
	// 	for(int x =0 ; x< 10; x++)
	// 		dp[1][x] = 1;
	// 	dp[1][1] = 0;
	// 	for(int x =0;x < 10; x++)
	// 	{
	// 		for(int y = 0; y< 10; y++)
	// 			if(gcd(x, y) != 1) vec[x].pb(y);
	// 	}
		
		ll L, R,re = 0;
		cin >> L >> R ;
		F(x,L,R)
		{
			if(pr(x)){cout << x << endl;re++;}

		}
		cout << re;
	}