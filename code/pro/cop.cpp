#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >=b ; i--)
#define pb push_back
#define mk make_pair
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
			int n, d;
			cin >> n >> d;
			pair <int, int > a[n];
			int i = 0, c ;
			for(auto &e : a)
			{
				
				cin >> e.first;
				if(i == 0)
					c = e.first;
				 e.second = i, i++;
			}


			sort(a, a+n);
			int de = c , re =0;
			int re1 = 0;
			for(auto Ree : a)
			{
				if(Ree.second == 0)
					continue;
				int R = Ree.first;
				re = max(abs(R - de), re);
				de = R;
			}
			// re = max( re1 , abs(a[n-1].first - c));
			reverse(a, a+n);
			de = c;
			for(auto Ree : a)
			{
				if(Ree.second == 0)
					continue;
				int R = Ree.first;
				re1 = max(abs(R - de), re1);
				de = R;
			}
			re = min (re , re1);

			if(re <= d)
				cout << "YES" << "\n";
			else 
				cout << "NO" << "\n";
			}
	}