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
		cout << setprecision(15) << fixed;
		int t;
		cin >> t;
		while(t--)
		{
			long  e = 0;
			int n;
			cin >> n;
			vector<int > vec(n),p(n);
			for(auto &f :vec)
				cin >> f;
			for(int x=0;x<n;x++)
			{
				long double d;
				cin >> d;
				e+= d*vec[x];
			}
			cout << e << "\n";
		}
	}
