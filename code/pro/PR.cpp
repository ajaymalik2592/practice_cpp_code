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
	if(b == 0)return a;
	else gcd(b, a%b);
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


vector <ll > vec[10], dots;
ll dp[20][10];

pair<ll , ll> fin(ll a)
{
	pair <ll , ll> pa;
	ll &re = pa.first;
	re = 0;

 	while(a)
	{
		pa.second = a%10;
		dots.pb(pa.second);
		a/=10;
		re++;

	}
	return pa;
}
ll go(ll a)
{
	dots.clear();
	if(a == 0) return 0;
	ll re = 9;
	pair <ll , ll > pa = fin(a);
	ll len = pa.first;
	ll f = pa.second;
	ll re1 = 9;
	if(len == 1) return a;

	for(int x =2; x < len; x++)
	{	
		re1 =  re;

		for(int y = 1; y < 10; y++)
		{
			ll &ans = dp[x][y];
			ans = 0;
			for(auto d : vec[y])
			{
				ans += dp[x-1][d];
			}
			re += ans;
		//	cout << y << " ans " << ans << " re "<< re << endl;
		}
		re1 = re - re1;
	}
	set<int > begging;
	for(int x = 1; x <= f; x++)
	{
		if(x == 1)continue;
		if(x == f)
		{
			begging.clear();
			begging.insert(dots[f-1]);
		for(int y = len - 2; y >= 0; y--)
		{

			if(y == 0)
			{
				for(auto j : vec[dots[1]])
				{
					if(j <= dots[0])re++;
				}
				continue;
			}
			ll gre = dots[y];
			for(int z = 0 ;z < gre; z++)
			{
				for(auto k : vec[z])
					{
						int ref = 1;
						for(int xx =0; xx< 10 ;xx++)
						{
							if(begging.find(xx) != begging.end() && gcd(xx, k) == 1)
								ref = 0;
						}
						if(ref)
							re += dp[y][k];
					}
				cout << x << " re " << z << "  " << re << endl;

			}
			begging.insert(dots[y]);
		}
	}
		else
		{
			begging.clear();
			begging.insert(dots[f-1]);

			for(auto je : vec[x])
			{
				check = 1;

				for(int zz =0; zz< 10; zz++)
				{
					if(begging.find(zz) != begging.end() && gcd(zz, je) == 1)
						check = 0;
				}
				if(check)
					re += dp[f-1][je];
			}
			cout << x << " re " << re << endl;

		}
		
	}
	return re;

}
int main()
	{
		for(int x =0 ; x< 10; x++)
			dp[1][x] = 1,dp[0][x] = 1;
		dp[0][1] = 0;
		dp[1][1] = 0;
		for(int x =0;x < 10; x++)
		{
			for(int y = 0; y< 10; y++)
				if(gcd(x, y) != 1) vec[x].pb(y);
		}
		
		ll L, R;
		cin >> L >> R ;
		ll big = go(R);
		for(int x =2 ; x<= 18; x++)
			for(int y =0 ;y <10 ; y++)
				dp[x][y] = 0;

		big -= go(L-1);
		cout << big;
	}