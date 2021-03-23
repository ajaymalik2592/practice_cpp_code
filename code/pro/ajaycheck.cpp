#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define all(v) v.begin() , v.end()
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
//ll mod =  998244353;
int main()
	{
		int t;
		cin >> t;
		while(t--)
		{
			ll n, k;
			cin >> n >>k;
			vector<ll> vec;
			vec.resize(n+1);
			int p = 1 , ma = -1;
			F(x,1,n)
			{
				cin >> vec[x];
				
			}
			ll d  = 0 , d1 = 1 , temp;
			set <int> se;
			F(x,1,k)
			{
				cin >> temp;
				se.insert(temp);
				d += temp;
				d1 = max(d1 ,temp);
			}
			for(int x = 1 ; x<= n ; x++)
			{
				if(ma < vec[x])
				{
					ma = vec[x];
					p = x;
				}
			}
			
			vector < ll > v (n+1 , 0);
			
			for(int x = 1 ; x<= d1 ; x++)
				v[x] = 1;
			for(int x = d1  +1 ; x < n ; x++)
			{
				for(auto d : se)
				{
					
					
						if(v[x-d] == 0)
						{
						v[x] = 1;
						break;
					}

				}
			}
			cout << "\n";


		}
	}
