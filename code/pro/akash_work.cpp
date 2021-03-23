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
ll mod = 987654319;
ll power(ll a , ll b )
{
	ll re =1;
	while(b)
	{
		if(b%2==1)
		{
			re*=a;
			re%=mod;
		}
		a*=a;
		a%=mod;
		b >>= 1;
	}
	return re;
}

int main()
	{

		ll n, max_weight;
		cin >> n >> max_weight;
		map<pair<int,int>, ll > ma;
		vector<ll> vec(n+1,0);
		for(int x=0; x<n-1; x++)
		{
			ll i, j, weight;
			cin >> i >> j >> weight;
			i--,j--;
			pair<int,int> pa;
			pa.first = min(i,j), pa.second = max(i,j);
			ma[pa] = weight;
			vec[i] = max(weight, vec[i]);
			vec[j] = max(weight, vec[j]);
		}
		ll re = 1, k = 0;
		for(int x=0; x<n;x++)
		{
			for(int y =x+1; y<n;y++)
			{
				pair<int,int> pa;
				pa.first = x, pa.second = y;
				if(ma.find(pa) == ma.end())
				{
					re *= 2 + max_weight -  min(vec[x], vec[y]);
					re %= mod;
					// k++;
					// cout << re  << " "  << k << "\n";
				}
			}
		}
		cout << re  << " "  << k;
	}

