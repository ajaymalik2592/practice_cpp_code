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
			int n;
			cin >> n;
			vector<int> vec(n), arr;
			ll sum = 0;
			for(auto &E : vec)
				cin >> E, sum += E;
			int k, x;
			cin >> k >> x;
			if(x==0)
			{
				cout << sum  << "\n";
				continue;
			}
			int po = 0;
			ll d = 0, e, d1 = 0;
			for(auto a : vec)
			{
				int g = (a^x) - a;
				arr.pb(g);
				if(g > 0)
					po++, d+= g;
				d1 += g;
				
			}
			sort(ALL(arr));
			reverse(ALL(arr));
			if(po == 0 )
			{
				e =0;
			}
			else if(k == n)
			{
				e =  max(0ll, d1) ;
				
			}
			else
			{
				if(k&1)
				{
					e = d;
				}
				else
				{
					if(po % 2 == 0)
						e = d;
					else if(po != n)
						e = max(d - arr[po-1], d + arr[po]);
					else
						e = d - arr[po-1];
				}
			}
			
			
			cout << sum + e << "\n";
		}
		return 0;
	}
