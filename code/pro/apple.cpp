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
int main()
	{
		speed
		int t;
		cin >> t;
		while(t--)
		{
			ll n, k, x;
			cin >> n;
			ll a[n] , sum = 0;
			for(auto &s : a)
			{
				cin >> s;
				sum += s;
			}
			cin >> k >> x;
			vector < ll > vec;
			for(auto s : a)
			{
				vec.pb((s ^ x)- s);
			}
			sort(ALL(vec));
			reverse(ALL(vec));
			ll p =0;
			for(int y = 0; y < n/k ; y++)
			{
				ll r =0;
				for(int d =0; d < k  ;d++)
				{
					r+=vec[k*y + d];
				}
				if(r > 0)
					p += r;
				else 
					break;
			}
			cout << sum + p << "\n";
		}
		}
