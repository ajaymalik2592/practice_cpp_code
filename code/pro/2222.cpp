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
		int n;
		cin >> n;
		ll a[n], b[n][2];
		vector<int> v[n+1];
		for(auto &d : v)
			d.resize(n,0);
		for(int x=0; x< n;x++)
		{
			cin >> a[x];
			v[x][x] = 1;
		}
		int q;
		cin >> q;
		
		for(int x=0 ;x< q; x++)
		{
			int e;
			cin >> e;
			if(e == 1)
			{
				int i, j;
				cin >> i >> j;
				for(int y = 0; y < n ; y++)
					int c = v[i][y] || v[j][y] , v[i][y] = c , v[j][y] = c;
				
               
			}
			else
			{
				int i;
				cin >> i;
				
				ll re1 = -INF, re2 = INF;
				for(int y =0 ;y < n ;y++)
				{
					if(v[i-1][y] == 1) re1 = max(re1, a[y]), re2 = min(re2 , a[y]);

				}
				cout << re1 - re2 << endl;
			}
		}
		
	}
